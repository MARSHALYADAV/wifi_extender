#if LWIP_FEATURES && !LWIP_IPV6

#define HAVE_NETDUMP 0

#include <ESP8266WiFi.h>
#include <lwip/napt.h>
#include <lwip/dns.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C pin definitions for the LCD (adjust if needed)
#define I2C_SDA 4
#define I2C_SCL 5

// Initialize the LCD (adjust the I2C address if required)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define NAPT 1000
#define NAPT_PORT 10

// Replace these with your own WiFi credentials
const char* PRIMARY_SSID   = "YOUR_PRIMARY_WIFI_SSID";
const char* PRIMARY_PASS   = "YOUR_PRIMARY_WIFI_PASSWORD";
const char* SECONDARY_SSID = "YOUR_SECONDARY_WIFI_SSID";
const char* SECONDARY_PASS = "YOUR_SECONDARY_WIFI_PASSWORD";

// Global variables for current connection and AP info.
String chosenSSID;
String chosenPass;
String apName;
String currentStationSSID;  // Keeps track of the active station network

#if HAVE_NETDUMP
#include <NetDump.h>
void dump(int netif_idx, const char* data, size_t len, int out, int success) {
  (void)success;
  Serial.print(out ? F("out ") : F(" in "));
  Serial.printf("%d ", netif_idx);
  netDump(Serial, data, len);
}
#endif

// Helper function to update the LCD with two lines of text.
void updateLCD(const String &line1, const String &line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

// Reconfigure the SoftAP based on the current station network.
void reconfigureAP() {
  // Use different AP names based on the active network.
  if (chosenSSID == PRIMARY_SSID) {
    apName = "AP_PRIMARY";
  } else {
    apName = "AP_SECONDARY";
  }
  WiFi.softAPdisconnect(true);
  WiFi.softAP(apName.c_str(), chosenPass.c_str());
  updateLCD("AP changed to", apName);
  Serial.printf("SoftAP reconfigured: %s\n", apName.c_str());
}

// Attempt to reconnect if the station connection is lost.
void attemptReconnect() {
  Serial.println("\nWiFi disconnected. Scanning for known networks...");
  updateLCD("WiFi lost!", "Scanning nets...");
  
  bool foundPrimary = false;
  bool foundSecondary = false;
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; i++) {
    String netSSID = WiFi.SSID(i);
    if (netSSID == PRIMARY_SSID) {
      foundPrimary = true;
      break;  // Priority to primary network.
    }
    if (netSSID == SECONDARY_SSID) {
      foundSecondary = true;
    }
  }
  
  if (foundPrimary) {
    chosenSSID = PRIMARY_SSID;
    chosenPass = PRIMARY_PASS;
  } else if (foundSecondary) {
    chosenSSID = SECONDARY_SSID;
    chosenPass = SECONDARY_PASS;
  } else {
    updateLCD("No networks", "found");
    return;
  }
  
  bool networkChanged = (chosenSSID != currentStationSSID);
  updateLCD("Reconnecting to", chosenSSID);
  WiFi.begin(chosenSSID, chosenPass);
  
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(500);
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    updateLCD("Connected:", WiFi.localIP().toString());
    if (networkChanged) {
      currentStationSSID = chosenSSID;
      reconfigureAP();
    }
  } else {
    updateLCD("Reconnect", "failed");
  }
}

void setup() {
  Serial.begin(115200);
  
  // Initialize I2C and LCD
  Wire.begin(I2C_SDA, I2C_SCL);
  lcd.init();
  lcd.backlight();
  updateLCD("WiFi Extender", "Starting...");
  
  Serial.println("\nWiFi Extender with Hotspot");
  
  // Set WiFi to station mode
  WiFi.mode(WIFI_STA);
  
  // Scan for the primary network.
  updateLCD("Scanning for", PRIMARY_SSID);
  bool foundPrimary = false;
  unsigned long startTime = millis();
  while (!foundPrimary && millis() - startTime < 30000) {
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; i++) {
      if (WiFi.SSID(i) == String(PRIMARY_SSID)) {
        foundPrimary = true;
        break;
      }
    }
    if (!foundPrimary) {
      updateLCD("Waiting for", PRIMARY_SSID);
      delay(2000);
    }
  }
  
  // Choose network credentials based on scan result.
  if (foundPrimary) {
    chosenSSID = PRIMARY_SSID;
    chosenPass = PRIMARY_PASS;
    apName = "AP_PRIMARY";
    Serial.println("Primary network found.");
  } else {
    chosenSSID = SECONDARY_SSID;
    chosenPass = SECONDARY_PASS;
    apName = "AP_SECONDARY";
    Serial.println("Using secondary network.");
  }
  
  currentStationSSID = chosenSSID;
  
  // Connect to the chosen network.
  updateLCD("Connecting to", chosenSSID);
  WiFi.begin(chosenSSID, chosenPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  updateLCD("Connected:", WiFi.localIP().toString());
  
  // Configure and start the SoftAP.
  auto& server = WiFi.softAPDhcpServer();
  server.setDns(WiFi.dnsIP(0));
  WiFi.softAPConfig(IPAddress(172,217,28,254), IPAddress(172,217,28,254), IPAddress(255,255,255,0));
  WiFi.softAP(apName.c_str(), chosenPass.c_str());
  updateLCD("Hotspot:", apName);
  
  // Initialize NAPT.
  err_t ret = ip_napt_init(NAPT, NAPT_PORT);
  if (ret == ERR_OK) {
    ret = ip_napt_enable_no(SOFTAP_IF, 1);
    if (ret == ERR_OK) {
      updateLCD("NAT active on", apName);
    }
  }
}

void loop() {
  // Check station connection; if lost, try reconnecting.
  if (WiFi.status() != WL_CONNECTED) {
    attemptReconnect();
  }
  delay(1000);
}

#else

void setup() {
  Serial.begin(115200);
  Serial.println("NAPT not supported in this configuration.");
}
void loop() {}

#endif
