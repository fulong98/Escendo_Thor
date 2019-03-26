#include "ColorRef.h"

ColorRef::ColorRef(bool isAllLowercase, bool isStdColorsEnabled) {
    _isAllLowercase = isAllLowercase;

    for (int i = 0; i < 256; i++) {
      for(int j = 0; j < 3; j++){
        _colorData[i][j] = 0;
      }
    }

    if (isStdColorsEnabled) {
        setStdColors();
    }
}

void ColorRef::defineNewColor(char index, int r, int g, int b) {
    if (_isAllLowercase) {
        index = tolower(index);
    }

    _colorData[index][0] = r;
    _colorData[index][1] = g;
    _colorData[index][2] = b;
}

uint32_t ColorRef::get32bitColor(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

uint32_t ColorRef::get32bitColorFromData(char index) {
    uint8_t r = _colorData[index][0];
    uint8_t g = _colorData[index][1];
    uint8_t b = _colorData[index][2];

    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

uint32_t ColorRef::getNeopixelColor(char index) {
    if (_isAllLowercase) {
        index = tolower(index);
    }
    return get32bitColorFromData(index);
}

void ColorRef::adjustGlobalBrightness(int brightness) {
    brightness = constrain(brightness, 1, 255);  //assert(brightness > 0)

    double scale = (double)brightness / _currentBrightness;

    double tempR, tempG, tempB;

    for (int i = 0; i < 256; i++) {
        tempR = scale * _colorData[i][0];
        tempG = scale * _colorData[i][1];
        tempB = scale * _colorData[i][2];

        _colorData[i][0] = (uint8_t)constrain(tempR, 0, 255);
        _colorData[i][1] = (uint8_t)constrain(tempG, 0, 255);
        _colorData[i][2] = (uint8_t)constrain(tempB, 0, 255);
    }

    _currentBrightness = brightness;
}

void ColorRef::adjustBrightness(char index, int brightness) {
    brightness = constrain(brightness, 1, 255);  //assert(brightness > 0)

    int maxBrightness = max(max(_colorData[index][0], _colorData[index][1]), _colorData[index][2]);

    double scale = 0.0;

    if (maxBrightness != 0) {
        scale = (double)brightness / maxBrightness;
    }

    double tempR, tempG, tempB;

    tempR = scale * _colorData[index][0];
    tempG = scale * _colorData[index][1];
    tempB = scale * _colorData[index][2];

    _colorData[index][0] = (uint8_t)constrain(tempR, 0, 255);
    _colorData[index][1] = (uint8_t)constrain(tempG, 0, 255);
    _colorData[index][2] = (uint8_t)constrain(tempB, 0, 255);
}

void ColorRef::setStdColors() {
    defineNewColor('w', 255, 255, 255);
    defineNewColor('k', 0, 0, 0);

    defineNewColor('r', 255, 0, 0);
    defineNewColor('g', 0, 255, 0);
    defineNewColor('b', 0, 0, 255);

    defineNewColor('y', 255, 255, 0);
    defineNewColor('c', 0, 255, 255);
    defineNewColor('m', 255, 0, 255);
}
