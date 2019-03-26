#include <Level.h>

Level game() ;
void setup() {
	
  Serial.begin(9600);
    
}

void loop(){
  int score;
  score=game.getScore();
    game.setScore();
    Serial.println(score);
    
    score=game.getScore();
    Serial.println(score);
    game.setColor(0);
    if (score<-100){game.setColor(1);}
}
