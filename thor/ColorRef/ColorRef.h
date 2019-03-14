#include <Arduino.h>

class ColorRef {
   public:
    ColorRef(bool isAllLowercase, bool isStdColorsEnabled);
    void defineNewColor(char index, int r, int g, int b);
    uint32_t getNeopixelColor(char index);

    //void adjustGlobalBrightness(int brightness);
    //void adjustBrightness(int brightness, char index);

   private:
    bool _isAllLowercase;
    uint32_t _colorData[256];
    uint32_t get32bitColor(uint8_t r, uint8_t g, uint8_t b);

    uint8_t* getRgbValuesFromColor(uint32_t c);

    void setStdColors();

    int _currentBrightness = 255;
};
