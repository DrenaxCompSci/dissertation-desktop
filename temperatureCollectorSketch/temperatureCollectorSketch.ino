const int tempPin = A0;
const int lightPin = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // -- Temperature --
  int sensorVal = analogRead(tempPin);
  //Serial.print("Temperature Sensor Value: ");
  //Serial.println(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  //Serial.print(", Volts: ");
  //Serial.print(voltage);
  //Serial.print(", degrees C: ");
  Serial.print("Temperature:");
  Serial.println(temperature);

  // -- Light --
  sensorVal = analogRead(lightPin);
  //Serial.print(", Light Sensor Value: ");
  Serial.print("Light:");
  Serial.println(sensorVal);

  // Delay querying of data
  delay(2000);
}
