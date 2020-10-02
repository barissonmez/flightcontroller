#include <Keyboard.h>
#include "RotationControl.h"

static const KeyCombination ALT_IncKeys(KEY_LEFT_CTRL, KEY_PAGE_UP, NULL, NULL);
static const KeyCombination ALT_DecKeys(KEY_LEFT_CTRL, KEY_PAGE_DOWN, NULL, NULL);
static const KeyCombination ALT_PressKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F1, NULL);
static const RotationControl alt_selector = RotationControl(2, 3, 4, 170, ALT_IncKeys, ALT_DecKeys, ALT_PressKeys);

static const KeyCombination VS_IncKeys(KEY_LEFT_CTRL, KEY_HOME, NULL, NULL);
static const KeyCombination VS_DecKeys(KEY_LEFT_CTRL, KEY_END, NULL, NULL);
static const KeyCombination VS_PressKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F2, NULL);
static const RotationControl vs_selector = RotationControl(5, 6, 7, 150, VS_IncKeys, VS_DecKeys, VS_PressKeys);

static const KeyCombination FLC_IncKeys(KEY_LEFT_CTRL, KEY_F10, NULL, NULL);
static const KeyCombination FLC_DecKeys(KEY_LEFT_CTRL, KEY_F12, NULL, NULL);
static const KeyCombination FLC_PressKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F3, NULL);
static const RotationControl flc_selector = RotationControl(8, 9, 10, 170, FLC_IncKeys, FLC_DecKeys, FLC_PressKeys);

static const KeyCombination HDG_IncKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F5, NULL);
static const KeyCombination HDG_DecKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F6, NULL);
static const KeyCombination HDG_PressKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F4, NULL);
static const RotationControl hdg_selector = RotationControl(16, 14, 15, 0, HDG_IncKeys, HDG_DecKeys, HDG_PressKeys);

static const KeyCombination CRS_IncKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F8, NULL);
static const KeyCombination CRS_DecKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F7, NULL);
static const KeyCombination CRS_PressKeys(KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_F9, NULL);
static const RotationControl crs_selector = RotationControl(A0, A1, A2, 0, CRS_IncKeys, CRS_DecKeys, CRS_PressKeys);

void setup()
{
}

void loop()
{
    alt_selector.tick();
    vs_selector.tick();
    flc_selector.tick();
    hdg_selector.tick();
    crs_selector.tick();
}
