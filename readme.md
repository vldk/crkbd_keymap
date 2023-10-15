## Keymap

```c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                             KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                             KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                KC_RALT, MO(_LOWER), KC_SPC,       KC_ENT, MO(_RAISE), KC_RGUI
    ),
	[_LOWER] = LAYOUT_split_3x6_3(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,                                  KC_6, KC_7, KC_8, KC_9, KC_0, C(RCTL(KC_BSPC)),
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
        KC_TRNS, KC_BRID, KC_BRIU, TD(TD_VOL), TD(TD_MEDIA), KC_VOLU,            KC_LBRC, KC_RBRC, KC_EQL, KC_MINS, KC_BSLS, KC_TILD,
                                        KC_TRNS, KC_TRNS , KC_TRNS,      KC_TRNS, KC_TRNS, KC_APP
    ),
	[_RAISE] = LAYOUT_split_3x6_3(
        QK_GESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                         KC_PSCR, C(RCTL(KC_LEFT)), KC_UP, C(RCTL(KC_RGHT)), KC_PGUP, C(RCTL(KC_BSPC)),
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                        KC_INS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_HOME,
        KC_TRNS, KC_F11, KC_F12, KC_NO, KC_NO, KC_CAPS,                     KC_DEL, KC_NO, KC_PPLS, KC_PMNS, KC_SLSH, KC_END,
                                        KC_TRNS, KC_TRNS, KC_RGUI,    KC_TRNS, KC_NO, KC_APP
    ),
	[_ADJUST] = LAYOUT_split_3x6_3(
        RGB_RST, RGB_ATG, KC_NO, KC_SCRL, KC_PAUS, KC_NUM,                      KC_CALC, KC_P7, KC_P8, KC_P9, KC_PAST, KC_PPLS,
        EH_RGHT, RGB_PST, RGB_UND, RGB_SAI, RGB_HUI, RGB_TOG,                   KC_PDOT, KC_P4, KC_P5, KC_P6, KC_PSLS, KC_PMNS,
        EH_LEFT, RGB_PCT, RGB_IDL, RGB_VAI, RGB_SPI, RGB_MOD,                   KC_P0,   KC_P1, KC_P2, KC_P3, KC_NO, KC_PENT,
                                        KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
    )
};
```

## Tab-Dacnce

**TD_MEDIA**
 1 tap -  MEDIA_PLAY_PAUSE
 2 taps - MEDIA_NEXT_TRACK
 3 taps - MEDIA_PREV_TRACK

**TD_VOL**
 1 tap -  AUDIO_VOL_DOWN
 2 taps - AUDIO_MUTE

## Combo
[_LOWER + _RAISE] => _ADJUST 

[TAB + Q] => ESC

## RGB

RGB implementation is based at `keyboards/crkbd/keymaps/rpbaptist``

- `RGB_UND`: Toggles underglow indicators on and off. Each layer has its own color.
- `RGB_IDL`: This will enable/disable idle mode. By default an "active" RGB mode will be used. When the idle timeout has exceeded the secondary animation will be activated, which is a passive animation. When switching to `GAMING` layer the timeout will be reduced and the idle animation changed to `RGB_MATRIX_RAINBOW_PINWHEELS`.
   When disabling idle mode, the current idle animation will be activated.
   On idling, on idling, the underglow layer indication will be deactivated and the animation RGB will be set instead.
- `RGB_ATG`: Cylces through three active modes: `RGB_MATRIX_SOLID_REACTIVE_SIMPLE` -> `RGB_MATRIX_TYPING_HEATMAP` -> `RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS`
- `RGB_PST`: Cycles through three passive modes: `RGB_MATRIX_SOLID_COLOR` -> `RGB_MATRIX_BREATHING` -> `RGB_MATRIX_CYCLE_ALL`
- `RGB_PCT`: Cycles through two, more colorful, passive modes: `RGB_MATRIX_RAINBOW_PINWHEELS` -> `RGB_MATRIX_CYCLE_LEFT_RIGHT`

## Building

 `qmk flash -kb crkbd -km vldk -bl avrdude-split-left`

 `qmk flash -kb crkbd -km vldk -bl avrdude-split-right`
