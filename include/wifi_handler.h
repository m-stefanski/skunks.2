#include <ESP8266WiFi.h>
#include <DNSServer.h>

const char *ssid = "skunks";
const char *hostname = "skunks";
IPAddress apIP(2, 1, 3, 7);
DNSServer dnsServer;

void setup_ap() {
  Serial.println("[wifi] Setting up...");
  WiFi.hostname(hostname);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid);
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.print("[wifi] SSID: ");
  Serial.println(ssid);
  Serial.print("[wifi] IP: ");
  Serial.println(myIP);
}

void setup_dns() {
  Serial.println("[dns] Serring up DNS...");
  dnsServer.setTTL(300);
  dnsServer.setErrorReplyCode(DNSReplyCode::ServerFailure);
  dnsServer.start(53, hostname, apIP);
  Serial.println(String("[dns] create entry for: ") + hostname);
}