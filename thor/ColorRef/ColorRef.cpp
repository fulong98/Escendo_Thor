#include "ColorRef.h"

ColorRef::ColorRef(bool isAllLowercase, bool isStdColorsEnabled) {
    _isAllLowercase = isAllLowercase;

    for (int i = 0; i < 256; i++) {
        _colorData[i] = 0;
    }

    if (isStdColorsEnabled) {
        setStdColors();
    }
}

void ColorRef::defineNewColor(char index, int r, int g, int b) {
    if (_isAllLowercase) {
        index = tolower(index);
    }

    _colorData[(int)index] = get32bitColor(r, g, b);
}

uint32_t ColorRef::get32bitColor(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

uint32_t ColorRef::getNeopixelColor(char index) {
    if (_isAllLowercase) {
        index = tolower(index);
    }

    if (_colorData[(int)index] != 0) {
        return _colorData[(int)index];
    } else {
        return 0;
    }
}


// need debugging
/*
void ColorRef::adjustGlobalBrightness(int brightness) {
    brightness = constrain(brightness, 0, 255);

    double scale = (double)brightness / _currentBrightness;

    uint8_t* temp;
    uint8_t r, g, b;

    for (int i = 0; i < 256; i++) {
        if (_colorData[i] != 0) {
            //Serial.println(i);
          
            temp = getRgbValuesFromColor(_colorData[i]);

            r = (uint8_t)(scale * temp[0]);
            g = (uint8_t)(scale * temp[1]);
            b = (uint8_t)(scale * temp[2]);
        
            r = (uint8_t)constrain(r, 0, 255);
            g = (uint8_t)constrain(g, 0, 255);
            b = (uint8_t)constrain(b, 0, 255);

            _colorData[i] = get32bitColor(r, g, b);
           
            //Serial.println(_colorData[i]);
        }
    }

    _currentBrightness = brightness;
}

void ColorRef::adjustBrightness(int brightness, char index) {

    if(_colorData[(int)index] == 0){
      return;
    }
  
    brightness = constrain(brightness, 0, 255);

    uint8_t* temp = getRgbValuesFromColor(_colorData[(int)index]);

    double scale = (double)brightness / _currentBrightness;

    uint8_t r, g, b;

    r = (uint8_t)(scale * temp[0]);
    g = (uint8_t)(scale * temp[1]);
    b = (uint8_t)(scale * temp[2]);

    r = (uint8_t)constrain(r, 0, 255);
    g = (uint8_t)constrain(g, 0, 255);
    b = (uint8_t)constrain(b, 0, 255);

    _colorData[(int)index] = get32bitColor(r, g, b);

    //Serial.println(_colorData[(int)index]);
}
*/

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

uint8_t* ColorRef::getRgbValuesFromColor(uint32_t c) {
    uint8_t rgb[3] = {c >> 16, c >> 8, c};

    return rgb;
}
