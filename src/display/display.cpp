#include "display.h"
#include "../config.h"
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold24pt7b.h> 
#include <Fonts/FreeMonoBold9pt7b.h>

static GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> epd(
    GxEPD2_154_D67(PIN_EPD_CS, PIN_EPD_DC, PIN_EPD_RST, PIN_EPD_BUSY)
);

void Display::init() {
    epd.init(115200);
    epd.setRotation(1);
    epd.setTextColor(GxEPD_WHITE);
    Serial.println("[Display] Init OK");
}
void Display::clear(){
    Serial.println("clear() display called");
    epd.setFullWindow();
    epd.firstPage();
    do{
        epd.fillScreen(GxEPD_WHITE);
    }while(epd.nextPage());
    epd.display();
    Serial.println("clear() display ended");
}

