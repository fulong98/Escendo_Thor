/*-----------------------------------*/
/* include libraries here
/*-----------------------------------*/
#include <Adafruit_NeoPixel.h >

#include "ThorLevel.h"

/*-----------------------------------*/
/* define macros here
/*-----------------------------------*/

#define NUM_BUTTONS 9

#define PIN_BUTTON0 0
#define PIN_BUTTON1 1
#define PIN_BUTTON2 2
#define PIN_BUTTON3 3
#define PIN_BUTTON4 4
#define PIN_BUTTON5 5
#define PIN_BUTTON6 6
#define PIN_BUTTON7 7
#define PIN_BUTTON8 8

/*-----------------------------------*/

enum PlayingState {
    SLEEP,
    STANDBY,
    GAMEPLAY
};

PlayingState playingState = GAMEPLAY;

/*-----------------------------------*/

int buttonPins[NUM_BUTTONS];
//ThorButton[NUM_BUTTONS] buttons;


void setup() {
    setupButtons();
}

void loop() {
    if (playingState == GAMEPLAY) {
        gameProtocol();
    }
}

/*-----------------------------------*/

int currentGameScore;

/*-----------------------------------*/
/* Setup functions
/*-----------------------------------*/
void setupButtons() {
    setupButtonPin(0, PIN_BUTTON0);
    setupButtonPin(1, PIN_BUTTON1);
    setupButtonPin(2, PIN_BUTTON2);
    setupButtonPin(3, PIN_BUTTON3);
    setupButtonPin(4, PIN_BUTTON4);
    setupButtonPin(5, PIN_BUTTON5);
    setupButtonPin(6, PIN_BUTTON6);
    setupButtonPin(7, PIN_BUTTON7);
    setupButtonPin(8, PIN_BUTTON8);

    for (int i = 0; i < NUM_BUTTONS; i++) {
        //buttons[i] = ThorButton(i);
    }
}

void setupButtonPin(int index, int pin) {
    buttonPins[index] = pin;
}

/*-----------------------------------*/
/* State functions
/*-----------------------------------*/

void updatePlayingState(PlayingState newState) {
    playingState = newState;
}

/*-----------------------------------*/
/* Gameplay functions
/*-----------------------------------*/

void gameProtocol() {
    ThorLevel level = ThorLevel(true);
    bool isGameOver = false;
    int currentLevel = level.getLevel();
    int prevLevel = level.getLevel();

    unsigned long startTime, currentTime;

    while(!isGameOver){
      randomButton(level.getNumColors());
      
      setAndCheckButtons();

      prevLevel = currentLevel;
      currentLevel = level.getLevel();
      if(prevLevel > currentLevel){
        levelUpProtocol();
      }
    }
}

void levelUpProtocol(){
  
}
