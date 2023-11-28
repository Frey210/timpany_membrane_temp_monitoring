
#include "BluetoothSerial.h" 

BluetoothSerial ESP_BT;

int analogPin = 25;

//Variabel untuk menyimpan data suhu
float suhu = 00;
int suhu1 = 00;

void setup() {
  //Komunikasi serial dengan baud 9600
  Serial.begin(9600);
  ESP_BT.begin("Timpany Microclimate");
}

void loop() {
  //Baca pin input
  suhu1 = analogRead(analogPin);

  //1'C = 10mV (sesuai datasheet)<br>// 5v /1023 = 4,883 mV (5v = tegangan refrensi, 1023 = resolusi 10 bit)
  // setiap kenaikan 1'C --> 10 / 4.883 = 2.0479

  //sehingga didapat rumus
  suhu = (suhu1/2.0479)+2;

  //hasil pembacaan akan ditampilkan di serial monitor
  Serial.println(suhu);
  ESP_BT.println(suhu);
  delay(1000);
}
