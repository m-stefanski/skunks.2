#include <Ticker.h>
#include <Adafruit_BME280.h>

#define SAMPLE_TIME_BME280 2

float temperature = 0;
float humidity = 0;
float pressure = 0;

Ticker timer_bme280;
Adafruit_BME280 bme;

void read_bme280(){
  temperature = bme.readTemperature();
  pressure = bme.readPressure() / 100.0F;
  humidity = bme.readHumidity();
  Serial.println(String("[bme280] Read: temperature: ") + temperature  + "*C, humidity: " + humidity + "%, pressure: " + pressure + " hPa");
}

void setup_bme280() {
  
  Serial.println("[bme280] Setting up...");
  bool status;
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("[bme280] ERROR: device not found!");
    while (1); // stopping the program
  }
  Serial.println("[bme280] Setting repeated measures");
  timer_bme280.attach(SAMPLE_TIME_BME280, read_bme280);
  Serial.println("[bme280] Ready");
}