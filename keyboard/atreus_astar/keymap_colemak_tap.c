#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // 0: colemak
  KEYMAP(
     /* KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                        KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,    \ */
     /* KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                        KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN, \ */
     /* KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                        KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, \ */
     KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,                        KC_J,     KC_L,    KC_U,     KC_Y,     KC_SCLN, \
     KC_A,     KC_R,     KC_S,     KC_T,     KC_D,                        KC_H,     KC_N,    KC_E,     KC_I,     KC_O, \
     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                        KC_K,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, \
     KC_ESC,   KC_LGUI,   KC_TAB,   KC_FN1,   KC_FN6,  KC_FN3,   KC_FN4,   KC_FN5,   KC_FN0,  KC_MINS,  KC_QUOT,  KC_ENT), \

  // 1: punctuation and numbers

  // *7890  |[]#!
  // +456~  @()^$
  // =123`  &{}%\
  //  0.      -'

  KEYMAP(
    SHIFT(KC_8),   KC_7,    KC_8,    KC_9,    KC_0,            SHIFT(KC_BSLS), KC_LBRC,        KC_RBRC,        SHIFT(KC_3), SHIFT(KC_1),\
    SHIFT(KC_EQL), KC_4,    KC_5,    KC_6,    SHIFT(KC_GRAVE), SHIFT(KC_2),    SHIFT(KC_9),    SHIFT(KC_0),    SHIFT(KC_6), SHIFT(KC_4),\
    KC_EQL,        KC_1,    KC_2,    KC_3,    KC_GRAVE,        SHIFT(KC_7),    SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_5), KC_BSLS,    \
    KC_TRNS,       KC_0,    KC_DOT,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   SHIFT(KC_MINS), SHIFT(KC_QUOT), KC_TRNS),\

  // 2: arrows and function keys
  KEYMAP(
     KC_INS,   KC_F7,    KC_F8,    KC_F9,    KC_F10,                       KC_HOME,  KC_RGHT,  KC_END,   KC_PGUP,  KC_PSCR, \
     KC_DEL,   KC_F4,    KC_F5,    KC_F6,    KC_F11,                       KC_LEFT,  KC_DOWN,  KC_UP,    KC_PGDN,  KC_PAUSE, \
     KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F12,                       KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_F13,   KC_F14, \
     KC_FN7,   KC_FN8,   KC_FN9,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_FN2)
};

enum macro_id {
  ECHOH,
  SHUFFLEFILES,
  GITCOMMIT,
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case ECHOH:
          return (record->event.pressed ?
              MACRO( D(LCTRL),
                     T(C),
                     U(LCTRL),
                     T(E),
                     T(C),
                     T(H),
                     T(O),
                     T(SPC),
                     T(MINS),
                     T(E),
                     T(SPC),
                     D(LSHIFT),
                     T(QUOT),
                     U(LSHIFT),
                     T(BSLS),
                     T(0),
                     T(3),
                     T(3),
                     D(LSHIFT),
                     T(9),
                     U(LSHIFT),
                     T(0),
                     D(LSHIFT),
                     T(QUOT),
                     U(LSHIFT),
                     T(SPC),
                     T(SCLN),
                     T(SPC),
                     T(C),
                     T(L),
                     T(E),
                     T(A),
                     T(R),
                     T(ENT),
                     END) :
              MACRO_NONE);

        case SHUFFLEFILES:
          return (record->event.pressed ?
              MACRO( D(LCTRL), T(C), U(LCTRL),
                     T(R),
                     T(U),
                     T(B),
                     T(Y),
                     T(SPC),
                     T(MINUS),
                     T(E),
                     T(SPC),
                     T(QUOT),
                     D(LSHIFT), T(D), U(LSHIFT),
                     T(I),
                     T(R),
                     T(LBRACKET),
                     D(LSHIFT), T(QUOT), U(LSHIFT),
                     D(LSHIFT), T(8), U(LSHIFT),
                     D(LSHIFT), T(QUOT), U(LSHIFT),
                     T(RBRACKET),
                     T(DOT),
                     T(M),
                     T(A),
                     T(P),
                     D(LSHIFT), T(LBRACKET), U(LSHIFT),
                     D(LSHIFT), T(BSLASH), U(LSHIFT),
                     T(D),
                     D(LSHIFT), T(BSLASH), U(LSHIFT),
                     T(GRAVE),
                     T(M),
                     T(V),
                     T(SPC),
                     D(LSHIFT), T(3), U(LSHIFT),
                     D(LSHIFT), T(LBRACKET), U(LSHIFT),
                     T(D),
                     D(LSHIFT), T(RBRACKET), U(LSHIFT),
                     T(SPC),
                     D(LSHIFT), T(3), U(LSHIFT),
                     D(LSHIFT), T(LBRACKET), U(LSHIFT),
                     T(D),
                     T(DOT),
                     T(S),
                     T(P),
                     T(L),
                     T(I),
                     T(T),
                     D(LSHIFT), T(9), U(LSHIFT),
                     D(LSHIFT), T(QUOT), U(LSHIFT),
                     D(LSHIFT), T(QUOT), U(LSHIFT),
                     D(LSHIFT), T(0), U(LSHIFT),
                     T(DOT),
                     T(S),
                     T(H),
                     T(U),
                     T(F),
                     T(F),
                     T(L),
                     T(E),
                     T(DOT),
                     T(J),
                     T(O),
                     T(I),
                     T(N),
                     D(LSHIFT), T(RBRACKET), U(LSHIFT),
                     T(GRAVE),
                     D(LSHIFT), T(RBRACKET), U(LSHIFT),
                     T(QUOT),
                     T(ENT),
                     END) :
              MACRO_NONE);
          /* ruby -e 'Dir["*"].map{|d|`mv #{d} #{d.split("").shuffle.join}`}' */

        case GITCOMMIT:
          return (record->event.pressed ?
              MACRO( D(LCTRL), T(C), U(LCTRL),
                     T(G),
                     T(I),
                     T(T),
                     T(SPC),
                     T(C),
                     T(O),
                     T(M),
                     T(M),
                     T(I),
                     T(T),
                     T(SPC),
                     T(MINS),
                     T(A),
                     T(M),
                     T(SPC),
                     T(QUOT),
                     T(S),
                     T(O),
                     T(M),
                     T(E),
                     T(T),
                     T(I),
                     T(M),
                     T(E),
                     T(S),
                     T(SPC),
                     T(I),
                     T(SPC),
                     T(E),
                     T(A),
                     T(T),
                     T(SPC),
                     T(P),
                     T(O),
                     T(O),
                     T(QUOT),
                     T(ENT),
                     END) :
              MACRO_NONE);

    }
    return MACRO_NONE;
}


const uint16_t PROGMEM fn_actions[] = {
  /* [0] = ACTION_LAYER_TAP_TOGGLE(1), */
  /* [1] = ACTION_LAYER_TAP_TOGGLE(2), */
  [0] = ACTION_LAYER_MOMENTARY(1),
  [1] = ACTION_LAYER_MOMENTARY(2),
  [2] = ACTION_FUNCTION(BOOTLOADER),
  [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [4] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT),
  [5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SPC),
  /* [6] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_BSPC), */
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),
  [7] = ACTION_MACRO(ECHOH),
  [8] = ACTION_MACRO(SHUFFLEFILES),
  [9] = ACTION_MACRO(GITCOMMIT),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
