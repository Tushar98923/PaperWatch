#pragma once
#include <Arduino.h>

namespace Display {
    void init();
    void clear();
    void drawtext(int x, int y, const   char* text);
    void update();
    void sleep();
}