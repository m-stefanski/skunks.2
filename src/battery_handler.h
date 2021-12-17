#include <Ticker.h>

#define PIN_BATTERY_VOLTAGE A0
#define SAMPLE_TIME_VOLTAGE 1

Ticker timer_voltage;

float battery_voltage = 0;

void read_battery() {
  float calculated_voltage = analogRead(PIN_BATTERY_VOLTAGE) / 1024.0F * 3.3;
  battery_voltage = calculated_voltage;
  Serial.println(String("[batt] voltage: ") + battery_voltage + " V");
}

void setup_battery() {
  Serial.println("[batt] Setting up...");
  timer_voltage.attach(SAMPLE_TIME_VOLTAGE, read_battery);
  Serial.println("[batt] Ready");
}