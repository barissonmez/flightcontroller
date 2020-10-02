#include "LedController.h"

static const LedController ledController;

static const LedControl FD_Led(0, CRGB::White);
static const LedControl AP_Led(1, CRGB::Blue);
static const LedControl PBRK_Led(2, CRGB::Red);

void setup() {
  Serial.begin(9600);
}

void loop() {

  doSomething();
  
}

void doSomething(){

    int theInt = String(millis()).substring(String(millis()).length() - 1, String(millis()).length()).toInt();

    switch (theInt) {
      case 0:
        ledController.Show(FD_Led);
        break;
      case 1:
        ledController.Show(AP_Led);
        break;
      case 2:
        ledController.Show(PBRK_Led);
        break;
      default:
        ledController.Hide(FD_Led);
        ledController.Hide(AP_Led);
        ledController.Hide(PBRK_Led);
        break;
    }
  
}
