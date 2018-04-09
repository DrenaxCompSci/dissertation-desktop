#include <ArduinoJson.h>

// Definining Sensor pins
const int tempPin = A0;
const int lightPin = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  StaticJsonBuffer<512> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject(); // creates space for a json object 
  
  // -- Temperature --
  int sensorVal = analogRead(tempPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
//  Serial.print("Temperature (degrees C):");
//  Serial.println(temperature);
  data["temperature"] = temperature;

  // -- Light --
  sensorVal = analogRead(lightPin);
  //Serial.print(", Light Sensor Value: ");
//  Serial.print("Light:");
//  Serial.println(sensorVal);
  data["light"] = sensorVal;
//
//  Serial.print("JSON Packet:");
  data.printTo(Serial);
  Serial.println();

  // Delay querying of data
  delay(1000);
}
