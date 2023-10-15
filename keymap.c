/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "common.h"


#ifdef COMBO_ENABLE

enum combos {
  TABQ_ESC,
};
const uint16_t PROGMEM tab_q[] = {KC_TAB, KC_Q, COMBO_END};
// const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};

combo_t key_combos[] = {
    [TABQ_ESC] = COMBO(tab_q, KC_ESC)
    // COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};

#endif


enum {
    TD_MEDIA,
    TD_VOL,
};

void dance_media(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_MPLY);
    } else if (state->count == 2) {
        tap_code (KC_MNXT);
    } else if (state->count == 3) {
        tap_code(KC_MPRV);
    } else {
        reset_tap_dance(state);
    }
}

void dance_vol(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1)  {
        tap_code(KC_VOLD);
    } else if (state->count == 2) {
        tap_code(KC_MUTE);
    } else {
        reset_tap_dance(state);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // [TD_MEDIA] =  ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT)
    [TD_MEDIA] =  ACTION_TAP_DANCE_FN(dance_media),
    [TD_VOL] = ACTION_TAP_DANCE_FN(dance_vol)
};


// end tap dance

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
                                        KC_RGUI, KC_TRNS, KC_TRNS,    KC_TRNS, KC_NO, KC_APP
    ),
	[_ADJUST] = LAYOUT_split_3x6_3(
        RGB_RST, RGB_ATG, KC_NO, KC_SCRL, KC_PAUS, KC_NUM,                      KC_CALC, KC_P7, KC_P8, KC_P9, KC_PAST, KC_PPLS,
        EH_RGHT, RGB_PST, RGB_UND, RGB_SAI, RGB_HUI, RGB_TOG,                   KC_PDOT, KC_P4, KC_P5, KC_P6, KC_PSLS, KC_PMNS,
        EH_LEFT, RGB_PCT, RGB_IDL, RGB_VAI, RGB_SPI, RGB_MOD,                   KC_P0,   KC_P1, KC_P2, KC_P3, KC_NO, KC_PENT,
                                        KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}


void suspend_power_down_keymap(void) {
#ifdef OLED_ENABLE
    oled_off();
#endif
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(true);
#endif
}

void suspend_wakeup_init_keymap(void) {
#ifdef OLED_ENABLE
    oled_on();
#endif
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(false);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef RGB_MATRIX_ENABLE
    process_record_user_rgb_matrix(keycode, record);
#endif

    return true;
}

// Override functions to save memory
// https://docs.qmk.fm/#/squeezing_avr?id=magic-keycodes
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
