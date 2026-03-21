#include <Arduino.h>
#include "config.h"
#include "display/display.h"

void setup() {
    Serial.begin(115200);
    delay(3000);
    Serial.println("Guardian Watch booting...");
    Display::init();
    Display::clear();
}

void loop() {

}