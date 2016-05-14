/*************************************************** 
  This is a library for the CAP1188 I2C/SPI 8-chan Capacitive Sensor

  Designed specifically to work with the CAP1188 sensor from Adafruit
  ----> https://www.adafruit.com/products/1602

  These sensors use I2C/SPI to communicate, 2+ pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
 
#include <TinyWireM.h>
#include <TinyCAP1188.h>

// Reset Pin is used for I2C
#define CAP1188_RESET  1

// For I2C, connect SDA to trinket/Gemma pin 0, SCL to Trinket/Gemma pin 2
// Use I2C with no reset pin
TinyCAP1188 cap = TinyCAP1188();

// Or...Use I2C, with reset pin
//TinyCAP1188 cap = TinyCAP1188(CAP1188_RESET);

//pin 1 is red led on Trinket
#define ledPin 1

void setup() {

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); //turn led off for 1 second
  delay(1000);
  
  // Initialize the sensor, you can pass in the i2c address or leave it at the default
  // if (!cap.begin(0x28)) {
  if (!cap.begin()) {
    while (1);
  }

  //if CAP1188 initialized OK, turn led on for 2 seconds
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
}

void loop() {
  uint8_t touched = cap.touched();

  if (touched == 0) {
    // No touch detected
    digitalWrite(ledPin, LOW);  //turn led off
    return;
  }
  
  for (uint8_t i=0; i<8; i++) {
    if (touched & (1 << i)) {
      digitalWrite(ledPin, HIGH);  //turn led on.
    }
  }
  delay(50);
}
