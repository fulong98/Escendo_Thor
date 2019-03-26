/*
	Level- a small library for Thor game to run.
*/

#ifndef Level_h
#define Level_h
#include "Arduino.h"

class Level
{
  public:
    Level();
    int getScore();
    int getDuration();
    void setColor(int neo_color);
    int getTime();
    void setScore(); // link with state


  private:
    uint8_t  _pin;
    int _score;
    int _time;
    int _color;
    const int _duration_level_1;
    const int _duration_level_2;
    const int _duration_level_3;
    const int _level_2_boundary_score;
    const int _level_3_boundary_score;
    const int _point;
};

#endif
