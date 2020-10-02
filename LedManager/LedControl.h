#include <FastLED.h>
#define DATA_PIN A0

class LedControl
{
  private:
  public:
    int _index = 0;
    CRGB::HTMLColorCode _color = CRGB::Red;
    LedControl(int index, CRGB::HTMLColorCode color)
    {
        _index = index;
        _color = color;
    };
};
