#include "ThorLevel.h"

ThorLevel::ThorLevel(bool useDefault) {
  
  _levelScoreThreshold[_getIndexFromLevel(1)] = 300;
  _levelScoreThreshold[_getIndexFromLevel(2)] = 500;
  _levelScoreThreshold[_getIndexFromLevel(3)] = 700;
  _levelScoreThreshold[_getIndexFromLevel(4)] = 900;
  _levelScoreThreshold[_getIndexFromLevel(5)] = 1000;

  _levelDuration[_getIndexFromLevel(1)] = 3000;
  _levelDuration[_getIndexFromLevel(2)] = 2500;
  _levelDuration[_getIndexFromLevel(3)] = 2000;
  _levelDuration[_getIndexFromLevel(4)] = 1500;
  _levelDuration[_getIndexFromLevel(5)] = 1000;

  _levelNumColors[_getIndexFromLevel(1)] = 1;
  _levelNumColors[_getIndexFromLevel(2)] = 2;
  _levelNumColors[_getIndexFromLevel(3)] = 3;
  _levelNumColors[_getIndexFromLevel(4)] = 4;
  _levelNumColors[_getIndexFromLevel(5)] = 5; 
}

void ThorLevel::setScore(int newScore) {
  _score = newScore;
  int ret = _checkLevel();
}

void ThorLevel::resetScore() {
  _score = 0;
  int ret = _checkLevel();
}

void ThorLevel::addScore() {
  _score += _increment;
  int ret = _checkLevel();
}

void ThorLevel::addScore(int num) {
  _score += num;
  int ret = _checkLevel();
}

void ThorLevel::minusScore() {
  _score -= _penalty;
  int ret = _checkLevel();
}

void ThorLevel::minusScore(int num) {
  _score -= num;
  int ret = _checkLevel();
}

int ThorLevel::getScore() {
  return _score;
}

void ThorLevel::resetLevel() {
  _level = 1;
}

void ThorLevel::setLevel(int newLevel) {
  _level = newLevel;
}

int ThorLevel::getLevel() {
  return _level;
}

void ThorLevel::setScoreThreshold(int level, int score){
  _levelScoreThreshold[_getIndexFromLevel(level)] = score;
  int ret = _checkLevel();
}

void ThorLevel::setDuration(int level, int dur){
  _levelDuration[_getIndexFromLevel(level)] = dur;
}

void ThorLevel::setNumColors(int level, int numColors){
  _levelScoreThreshold[_getIndexFromLevel(level)] = numColors;
}

void ThorLevel::setScoreIncrement(int level, int increment){
  _levelScoreIncrement[_getIndexFromLevel(level)] = increment;
}

void ThorLevel::setScorePenalty(int level, int penalty){
  _levelScorePenalty[_getIndexFromLevel(level)] = penalty;
}

int ThorLevel::_checkLevel() {
  for (int i = 0; i < MAX_LEVEL; i++) {
    if (_score < _levelScoreThreshold[i]) {
      _level = _getLevelFromIndex(i);
      return _level;
    }
  }

  return MAX_LEVEL + 1;
}

int ThorLevel::_getIndexFromLevel(int level) {
  return (level - 1);
}

int ThorLevel::_getLevelFromIndex(int index) {
  return (index + 1);
}
