/*
	Level- a small library for Thor game to run.
*/
#include <Arduino.h>
#include "Level.h"


Level::Level(uint8_t pin)
:   _pin(pin)
,   _score(0)
,   _point(40)
,   _duration_level_1(3)
,   _duration_level_2(2)
,   _duration_level_3(1)
,   _time(40)
,   _color(1)
,   _level_2_boundary_score(300)
,   _level_3_boundary_score(500)
{
}
//get the score
int Level::getScore()
{
    return _score;
}
//set the score 
//color=1 -> addScore
//color=0 -> minnusScore
void Level::setScore()
{
    if(_color == 1)
    {
        _score = _score + _point;
    }
    else 
    {
        _score = _score - _point;
    }
}
//get Game Level Duration 
//level 1: 3seconds
//level 2:2seconds
//level 3:2seconds
int Level::getDuration()
{   
    
    if(_score >= 300 and _score < 500){return  _duration_level_2;}
    if(_score >= 500){return _duration_level_3;}
    else { return _duration_level_1;}
    
}
//initialse the score and score before Game start(level 1)

//set color so that during setScore it will auto addMark/MinusMark
void Level::setColor(int neo_color)
{
    _color = neo_color;
}

int Level::getTime()
{
    return _time;
}


