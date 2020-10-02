#include "LedControl.h"
#define DATA_PIN 10

class LedController
{
  private:
    CRGB leds[10];
  public:         
    LedController(int brightness = 5)
    {
      FastLED.clear();
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, sizeof(leds));
      FastLED.setBrightness(brightness);
    };

    void Show(LedControl ledControl){
      leds[ledControl._index] = ledControl._color;
      FastLED.show();
    };

    void Hide(LedControl ledControl){
      leds[ledControl._index] = CRGB::Black;
      FastLED.show();
    };
};
