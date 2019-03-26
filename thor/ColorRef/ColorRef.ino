#include "ColorRef.h"

void setup() {
  Serial.begin(9600);

  //setting whether the ref automatically convert uppercase char input into lower case
  //WARNING: this reduces the total number of possible colors to be stored by almost half
  bool isAllLowercase = false;

  //setting whether to automatically include standard colors in the dictionary
  bool isStdColorsEnabled = true;

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
  
  ColorRef colorRef = ColorRef(isAllLowercase, isStdColorsEnabled);  

  //color 'key' is defined using one char i.e. 256 possible colors in total
  colorRef.defineNewColor('o', 255, 128, 0);

  Serial.print("Getting 'o' color for neopixel: ");
  Serial.println(colorRef.getNeopixelColor('o'));

  Serial.print("Getting some nonexistent color: ");
  Serial.println(colorRef.getNeopixelColor('j'));

  //overwriting color definition
  colorRef.defineNewColor('o', 254, 0, 0);

  Serial.print("Getting new 'o' color for neopixel: ");
  Serial.println(colorRef.getNeopixelColor('o'));

  //adjusting brightness of one color | brightness range = [0, 255]
  colorRef.adjustBrightness('o', 200);

  //adjusting brightness of ALL colors | brightness range = [0, 255]
  colorRef.adjustGlobalBrightness(200);
}

void loop() {
  
}
