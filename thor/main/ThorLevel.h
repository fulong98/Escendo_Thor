#include <Arduino.h>

#define MAX_LEVEL 5

class ThorLevel {

  public:
    ThorLevel(bool useDefault);

    void resetScore();
    void setScore(int newScore);

    void addScore();
    void minusScore();

    void addScore(int num);
    void minusScore(int num);

    int getScore();

    void resetLevel();
    void setLevel(int newLevel);

    int getLevel();

    unsigned int getDuration();

    int getNumColors();

    void setScoreThreshold(int level, int score);
    void setDuration(int level, unsigned int dur);
    void setNumColors(int level, int numColors);
    void setScoreIncrement(int level, int increment);
    void setScorePenalty(int level, int penalty);
  private:

    int _score = 0;
    int _increment = 1;
    int _penalty = 1;

    int _level = 1;
    unsigned int _duration = 3000;
    int _numColors = 1;

    bool _multipleColor(int level);

    int _levelScoreThreshold[MAX_LEVEL];
    unsigned int _levelDuration[MAX_LEVEL];
    int _levelNumColors[MAX_LEVEL];
    int _levelScoreIncrement[MAX_LEVEL];
    int _levelScorePenalty[MAX_LEVEL];

    int _getIndexFromLevel(int level);
    int _getLevelFromIndex(int index);
    int _checkLevel();
};
