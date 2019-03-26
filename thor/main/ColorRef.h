#include <Arduino.h>

class ColorRef {
   public:
    ColorRef(bool isAllLowercase, bool isStdColorsEnabled);
    void defineNewColor(char index, int r, int g, int b);
    uint32_t getNeopixelColor(char index);

    void adjustGlobalBrightness(int brightness);
    void adjustBrightness(char index, int brightness);

   private:
    bool _isAllLowercase;
    uint8_t _colorData[][3];

    uint32_t get32bitColorFromData(char index);
    uint32_t get32bitColor(uint8_t r, uint8_t g, uint8_t b);

    void setStdColors();

    int _currentBrightness = 255;
};
