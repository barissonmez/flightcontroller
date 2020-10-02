#include <Keyboard.h>
#include "ButtonControl.h"

#define KEY_A 97
#define KEY_D 100
#define KEY_F 102
#define KEY_N 110
#define KEY_O 111
#define KEY_P 112
#define KEY_R 114
#define KEY_Z 122

/*LEDS*/
static const LedControl FD_Led(0, CRGB::White);
static const LedControl LOC_Led(1, CRGB::White);
static const LedControl NAV_Led(2, CRGB::White);
static const LedControl AP_Led(3, CRGB::Blue);
static const LedControl APPR_Led(4, CRGB::White);
static const LedControl YD_Led(5, CRGB::White);
static const LedControl A_THR_Led(6, CRGB::Purple);
static const LedControl P_BRK_Led(7, CRGB::Red);


/*BUTTONS*/
static const KeyCombination FD_Keys(KEY_LEFT_CTRL, KEY_F, NULL, NULL);
static const ButtonControl FD_Btn = ButtonControl(2, FD_Keys);

static const KeyCombination NAV_Keys(KEY_LEFT_CTRL, KEY_N, NULL, NULL);
static const ButtonControl NAV_Btn = ButtonControl(3, NAV_Keys);

static const KeyCombination APPR_Keys(KEY_LEFT_CTRL, KEY_A, NULL, NULL);
static const ButtonControl APPR_Btn = ButtonControl(4, APPR_Keys);

static const KeyCombination AP_Keys(KEY_Z, NULL, NULL, NULL);
static const ButtonControl AP_Btn = ButtonControl(5, AP_Keys);

static const KeyCombination YD_Keys(KEY_LEFT_CTRL, KEY_D, NULL, NULL);
static const ButtonControl YD_Btn = ButtonControl(6, YD_Keys);

static const KeyCombination LOC_Keys(KEY_LEFT_CTRL, KEY_O, NULL, NULL);
static const ButtonControl LOC_Btn = ButtonControl(7, LOC_Keys);

static const KeyCombination ATHR_Keys(KEY_LEFT_SHIFT, KEY_R, NULL, NULL);
static const ButtonControl ATHR_Btn = ButtonControl(8, ATHR_Keys);

static const KeyCombination PBRK_Keys(KEY_P, NULL, NULL, NULL);
static const ButtonControl PBRK_Btn = ButtonControl(9, PBRK_Keys, true);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
    FD_Btn.init(FD_Led);
    NAV_Btn.init(NAV_Led);
    APPR_Btn.init(APPR_Led);
    AP_Btn.init(AP_Led);
    YD_Btn.init(YD_Led);
    LOC_Btn.init(LOC_Led);
    ATHR_Btn.init(A_THR_Led);
    PBRK_Btn.init(P_BRK_Led);
}
