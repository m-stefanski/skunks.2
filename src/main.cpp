#include <Arduino.h>
#include "bme280_handler.h"
#include "sds011_handler.h"
#include "battery_handler.h"
#include "wifi_handler.h"
#include "web_handler.h"

void setup() {
  Serial.begin(9600);
  Serial.write(12);
  Serial.println("[app] Initializing...");
  setup_bme280();
  setup_sds011();
  setup_battery();
  setup_ap();
  setup_dns();
  setup_web();
  Serial.println("[app] Finished initializing.");
}

void loop() {
  server.handleClient();
  sds011.loop();
  dnsServer.processNextRequest();
}