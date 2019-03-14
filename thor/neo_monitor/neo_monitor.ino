#include <Adafruit_NeoPixel.h>

#define STRIP_PIN 6
#define NUM_PIXELS 16

#define COLOR_VAL 0xff00
long choice;
Adafruit_NeoPixel strip(NUM_PIXELS, STRIP_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
    randomSeed(analogRead(0));
    Serial.begin(9600);

    strip.begin();
    lightRandom();

    strip.show();
}

void loop() {
    choice = Serial.parseInt();
    
    if (strip.getPixelColor(choice-1) == COLOR_VAL) {
        strip.clear();
        strip.show();
        delay(2000);
        lightRandom();               
    }
}

void lightRandom() {
//  if it is not okay to have 2 times the same places.
    while (1) {
        int pos = random(NUM_PIXELS);
        if (choice-1 != pos){
            choice = pos;
            break;
        }
    }
    
    strip.setPixelColor(choice, COLOR_VAL);
    strip.show();
    Serial.println(choice+1);
}
//      if it is okay to have 2 times the same places.
//
//    
//    int ran=random(NUM_PIXELS);
//    strip.setPixelColor(ran, COLOR_VAL);
//    strip.show();
//    Serial.println(ran+1);
//    
//}
