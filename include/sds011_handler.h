#include <SDS011.h>

SDS011 sds011;

float pm25;
float pm10;

void read_sds011(float pm25Value, float pm10Value){
  pm25 = pm25Value;
  pm10 = pm10Value;
  Serial.println(String("[sds011] Read: PM 2.5: ") + pm25  + ", PM 10: " + pm10);
}

void setup_sds011(){
  Serial.println("[sds011] Setting up...");
  sds011.setup(&Serial);
  sds011.onData(read_sds011);
  sds011.setWorkingPeriod(5);
  Serial.println("[sds011] Ready");
}