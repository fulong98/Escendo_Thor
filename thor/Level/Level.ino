#include <Level.h>
#include <Adafruit_NeoPixel.h>
#include <ButtonMIT.h>

<<<<<<< HEAD:thor/Level/Level.ino
Level game() ;
=======
#define STRIP_PIN 6
#define NUM_PIXELS 3
#define LIGHT_OFFSET 0
#define NUM_LIGHT (NUM_PIXELS - LIGHT_OFFSET)
#define COLOR_VAL 0xff00
long choice;
Adafruit_NeoPixel strip(NUM_PIXELS, STRIP_PIN, NEO_RGB + NEO_KHZ800);
Level game(1) ;
// Button declaration, the number of light must be equal to the number of buttons in this case 2
#define NUM_BUTTONS NUM_LIGHT
#define LIGHT_TIMEOUT 5000 //led will switch to other position if you dont press the correct button in 5 seconds
#define UPDATE_DELAY 1000   // after u press the correct button, the light will switch to random position in 1 second
int litLedPos; // position of the led 
unsigned long timeLightUpdate;  //to make sure that the time is correctly set up with the delay and timeout


Button buttons[NUM_BUTTONS] = {
    Button(0), Button(1),
      Button(2),
//     Button(3),
//    Button(4), Button(5), Button(6), Button(7),
//    Button(8)
};

>>>>>>> a46d8f3892f27d9f1c805a2423f1c7ad174152e4:thor/Level/testing/testing.ino
void setup() {
	randomSeed(analogRead(0));
  Serial.begin(9600);
  strip.begin();
//  lightRandom();
  strip.show();
  for (int i = 0; i < NUM_BUTTONS; i++) {
        buttons[i].begin();
    }
    lightTurnRandomPixel();
    
}

void loop(){
  int score;
//  choice = Serial.parseInt();
  score=game.getScore();
//  Serial.println(score);
  
      if (buttons[litLedPos].pressed()  ) {
        game.setScore();
        Serial.println("Setting Score");
        Serial.println(score);        
        score=game.getScore();
        Serial.println("Score:");
        Serial.println(score);
        lightTurnOffAll();
        delay(UPDATE_DELAY);
        lightTurnRandomPixel();
        
        
    }
    else if(millis() - timeLightUpdate > LIGHT_TIMEOUT)
    {
      Serial.println("Changing position");
      lightTurnOffAll();
      delay(UPDATE_DELAY);
      lightTurnRandomPixel();
      
    }
    
//    if (strip.getPixelColor(choice-1) == COLOR_VAL) // if the neopixel lighted up , then the neopixel has color == COLOR_VAL
//    {
//        strip.clear();
//        strip.show();
//        delay(2000);
//        lightRandom();   
//        game.setScore();
//        Serial.println(score);        
//        score=game.getScore();
//        Serial.println(score);            
//    }
    
<<<<<<< HEAD:thor/Level/Level.ino
    score=game.getScore();
    Serial.println(score);
    game.setColor(0);
    if (score<-100){game.setColor(1);}
=======
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
////
void lightTurnRandomPixel() {
    // Keep time to keep track timeout
    timeLightUpdate = millis();
//Choose 1 or 2
    //1. Pick until get different position
//    while (1) {
//        int pos = random(NUM_LIGHT);
//        if (litLedPos != pos) {
//            litLedPos = pos;
//            break;
//        }
//    }
  //2. random led can spawn in the same position more than one
    litLedPos= random(NUM_LIGHT);
    Serial.println("Position_LED:");
    Serial.println(litLedPos);
    
    strip.setPixelColor(litLedPos + LIGHT_OFFSET, COLOR_VAL);
    strip.show();
>>>>>>> a46d8f3892f27d9f1c805a2423f1c7ad174152e4:thor/Level/testing/testing.ino
}
void lightTurnOffAll() {
    for (int i = 0; i < NUM_LIGHT; i++) {
        strip.setPixelColor(i + LIGHT_OFFSET, 0);
    }
    strip.show();
  }
