#include <Arduino.h>
#include <Bounce2.h>
#include "KeyCombination.h"
#include "LedController.h"

static const LedController ledController;

class ButtonControl
{
private:
    Bounce _button = Bounce();
    KeyCombination _keys = KeyCombination(NULL, NULL, NULL, NULL);
    bool _isSwitch = false;
    int _lastSwitchValue = LOW;
    int _buttonStateIsOn = false;
    int _ledStateIsOn = false;
    void pressAndReleaseKeys()
    {
      Keyboard.press(_keys.getKey1());
      Keyboard.press(_keys.getKey2());
      Keyboard.press(_keys.getKey3());
      Keyboard.press(_keys.getKey4());

      delay(100);
      
      Keyboard.release(_keys.getKey4());
      Keyboard.release(_keys.getKey3());
      Keyboard.release(_keys.getKey2());
      Keyboard.release(_keys.getKey1());
    };
public:
    // Parameterized Constructor
    ButtonControl(int btnPin, KeyCombination keys, bool isSwitch= false)
    {
      Keyboard.begin();
      
      _button = Bounce();
      _button.attach(btnPin, INPUT_PULLUP);
      _button.interval(25);

      _keys = keys;

      _isSwitch = isSwitch;

    };

    void init(LedControl ledControl)
    {
        _button.update();

        if(_isSwitch){

          int switchValue = _button.read();

          if(switchValue != _lastSwitchValue){
            pressAndReleaseKeys();
            _lastSwitchValue = switchValue;
          }

          if(switchValue == HIGH)
            _ledStateIsOn = false;
          else
            _ledStateIsOn = true;
            
        }else{
          if (_button.fell()){
            pressAndReleaseKeys();
            _ledStateIsOn = !_ledStateIsOn;
          }
        }

        if(_ledStateIsOn)
          ledController.Show(ledControl);
        else
          ledController.Hide(ledControl);
    };
};
