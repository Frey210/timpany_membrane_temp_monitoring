//GY-906 
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
float temp;

//bluetooth
#include <SoftwareSerial.h>
SoftwareSerial bt(19, 18); // RX, TX


void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  mlx.begin();  
}

void loop() {
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  Serial.println();

  temp = mlx.readObjectTempC();
  if(bt.available){
    bt.print(temp);
  }
  
  delay(500);
}