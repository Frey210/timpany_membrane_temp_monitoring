
#include "BluetoothSerial.h" 

BluetoothSerial ESP_BT;

#define ADC_VREF_mV    3300.0 
#define ADC_RESOLUTION 4096.0
#define PIN_LM35       14 

void setup() {
  //Komunikasi serial dengan baud 9600
  Serial.begin(9600);
  ESP_BT.begin("Timpany Microclimate");
}

void loop() {
  // read the ADC value from the temperature sensor
  int adcVal = analogRead(PIN_LM35);
  // convert the ADC value to voltage in millivolt
  float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  // convert the voltage to the temperature in °C
  float tempC = milliVolt / 10;

  // hasil pembacaan akan ditampilkan di serial monitor jika tidak ada bluetooth terhubung
  if (ESP_BT.hasClient()) {
    ESP_BT.println(tempC);
  } else {
    Serial.println(tempC);
  }
  delay(1000);
}
