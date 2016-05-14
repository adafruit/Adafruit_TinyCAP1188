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
#define CAP1188_RESET  9

// For I2C, connect SDA to your Arduino's SDA pin, SCL to SCL pin
// On UNO/Duemilanove/etc, SDA == Analog 4, SCL == Analog 5
// On Leonardo/Micro, SDA == Digital 2, SCL == Digital 3
// On Mega/ADK/Due, SDA == Digital 20, SCL == Digital 21

// Use I2C, no reset pin!
TinyCAP1188 cap = TinyCAP1188();

// Or...Use I2C, with reset pin
//TinyCAP1188 cap = TinyCAP1188(CAP1188_RESET);


void setup() {

  // Initialize the sensor, if using i2c you can pass in the i2c address
  // if (!cap.begin(0x28)) {
  if (!cap.begin()) {
    while (1);
  }
}

void loop() {
  uint8_t touched = cap.touched();

  if (touched == 0) {
    // No touch detected
    return;
  }
  
  for (uint8_t i=0; i<8; i++) {
    if (touched & (1 << i)) {
      //do something here
    }
  }
  delay(50);
}

