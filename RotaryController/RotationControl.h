#include <Arduino.h>
#include <RotaryEncoder.h>
#include <Bounce2.h>
#include <Keyboard.h>
#include "KeyCombination.h"

class RotationControl
{
private:
    RotaryEncoder _encoder = RotaryEncoder(NULL, NULL);
    Bounce _button = Bounce();
    int _lastPos = 0;
    int _newPos = 0;
    unsigned long _lastTime = 0;
    bool _incKeyPressed = false;
    bool _decKeyPressed = false;
    int _defaultPeriod = 50;
    int _period = 0;
    KeyCombination _incKeys = KeyCombination(NULL, NULL, NULL, NULL);
    KeyCombination _decKeys = KeyCombination(NULL, NULL, NULL, NULL);
    KeyCombination _pressKeys = KeyCombination(NULL, NULL, NULL, NULL);

public:
    // Parameterized Constructor
    RotationControl(int _encoderClkPin, int _encoderDtPin, int _encoderBtnPin, int period, KeyCombination incKeys, KeyCombination decKeys, KeyCombination pressKeys)
    {

        _encoder = RotaryEncoder(_encoderClkPin, _encoderDtPin);
        _button = Bounce();
        _button.attach(_encoderBtnPin, INPUT_PULLUP);

        if (period < _defaultPeriod)
            _period = _defaultPeriod;
        else
            _period = period;
        Keyboard.begin();
        _button.attach(_encoderBtnPin, INPUT_PULLUP);
        _button.interval(25);

        _incKeys = incKeys;
        _decKeys = decKeys;
        _pressKeys = pressKeys;
    };

    void tick()
    {
        _encoder.tick();
        unsigned long now = millis();

        if (now - _lastTime >= _period)
        {
            _lastTime = now;
            _newPos = _encoder.getPosition();

            if (_lastPos != _newPos)
            {
                if (_newPos > _lastPos)
                {
                    if (!_incKeyPressed)
                    {
                        Keyboard.press(_incKeys.getKey1());
                        Keyboard.press(_incKeys.getKey2());
                        Keyboard.press(_incKeys.getKey3());
                        Keyboard.press(_incKeys.getKey4());

                        _incKeyPressed = true;
                    }
                }
                else
                {
                    if (!_decKeyPressed)
                    {
                        Keyboard.press(_decKeys.getKey1());
                        Keyboard.press(_decKeys.getKey2());
                        Keyboard.press(_decKeys.getKey3());
                        Keyboard.press(_decKeys.getKey4());

                        _decKeyPressed = true;
                    }
                }
                _lastPos = _newPos;
            }
            else
            {
                if (_incKeyPressed)
                {
                    Keyboard.release(_incKeys.getKey4());
                    Keyboard.release(_incKeys.getKey3());
                    Keyboard.release(_incKeys.getKey2());
                    Keyboard.release(_incKeys.getKey1());
                    _incKeyPressed = false;
                }
                if (_decKeyPressed)
                {
                    Keyboard.release(_decKeys.getKey4());
                    Keyboard.release(_decKeys.getKey3());
                    Keyboard.release(_decKeys.getKey2());
                    Keyboard.release(_decKeys.getKey1());
                    _decKeyPressed = false;
                }
            }
        }

        _button.update(); // Update the Bounce instance

        if (_button.fell())
        {
            Keyboard.press(_pressKeys.getKey1());
            Keyboard.press(_pressKeys.getKey2());
            Keyboard.press(_pressKeys.getKey3());
            Keyboard.press(_pressKeys.getKey4());

            delay(50);
            Keyboard.release(_pressKeys.getKey4());
            Keyboard.release(_pressKeys.getKey3());
            Keyboard.release(_pressKeys.getKey2());
            Keyboard.release(_pressKeys.getKey1());
        }
    };
};
