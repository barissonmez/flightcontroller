#include "LedControl.h"
#include "ListLib.h"

#define DATA_PIN A0

class LedController
{
  private:
    CRGB leds[100];
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
