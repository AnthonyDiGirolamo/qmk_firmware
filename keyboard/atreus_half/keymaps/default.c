// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "atreus_half.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP( /* Base */
  KC_A,  KC_B,  KC_C, KC_D, KC_E, \
  KC_F,  KC_G,  KC_H, KC_I, KC_J, \
  KC_K,  KC_L,  KC_M, KC_N, KC_O, KC_P, \
  KC_Q,  KC_R,  KC_S, KC_LSFT, KC_RSFT \
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
