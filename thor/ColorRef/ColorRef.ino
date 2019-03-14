#include "ColorRef.h"

void setup() {
  Serial.begin(9600);

  //setting whether the ref automatically convert uppercase char input into lower case
  bool isAllLowercase = false;

  //setting whether to automatically include standard colors in the dictionary
  bool isStdColorsEnabled = true;
  
  ColorRef colorRef = ColorRef(isAllLowercase, isStdColorsEnabled);  

  /*
   * standard colors
   * 
   * 'w': white
   * 'k': black
   * 
   * 'r': red
   * 'g': green
   * 'b': blue
   * 
   * 'y': yellow
   * 'c': cyan
   * 'm': magenta
   */

  colorRef.defineNewColor('o', 255, 128, 0);

  Serial.print("Getting 'o' color for neopixel: ");
  Serial.println(colorRef.getNeopixelColor('o'));

  Serial.print("Getting some nonexistent color: ");
  Serial.println(colorRef.getNeopixelColor('j'));

  //overwriting color definition
  colorRef.defineNewColor('o', 254, 0, 0);

  Serial.print("Getting new 'o' color for neopixel: ");
  Serial.println(colorRef.getNeopixelColor('o'));
}

void loop() {
  
}
