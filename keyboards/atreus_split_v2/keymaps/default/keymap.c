// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_id {
  LAYER_COLEMAK,
  LAYER_QWERTY,
  LAYER_SYMBOLS,
  LAYER_FNARROWS,
  LAYER_MOUSEMACRO,
};

enum macro_id {
  ECHOH,
  GITCOMMIT,
};

// Basic Keycodes: https://docs.qmk.fm/#/keycodes_basic
//                 docs/keycodes_basic
// Layers: https://docs.qmk.fm/#/keymap
//         docs/keymap
// Macros: https://docs.qmk.fm/#/feature_advanced_keycodes
//         docs/feature_advanced_keycodes.md
//
// __v is KC_TRNS
//   This becomes the key defined in that position on the lower layer (transparent / layer fall-through).
//
// ___ is KC_NO
//   is no action (no layer fall-through)

#define HYPER_ESC MT(MOD_LGUI|MOD_LCTL|MOD_LALT, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_COLEMAK] = \
LAYOUT(
       KC_Q,      KC_W,    KC_F,   KC_P,               KC_G,                 KC_INS,              /*|*/ KC_PGUP,                     KC_J,                KC_L,              KC_U,    KC_Y,    KC_SCLN, \
       KC_A,      KC_R,    KC_S,   KC_T,               KC_D,                 KC_DEL,              /*|*/ KC_PGDN,                     KC_H,                KC_N,              KC_E,    KC_I,    KC_O,    \
       KC_Z,      KC_X,    KC_C,   KC_V,               KC_B,                 MT(MOD_LCTL,KC_ESC), /*|*/ MT(MOD_LALT,KC_ENT),         KC_K,                KC_M,              KC_COMM, KC_DOT,  KC_SLSH, \
       HYPER_ESC, KC_LGUI, KC_TAB, MO(LAYER_FNARROWS), MT(MOD_LSFT,KC_BSPC), KC_ESC,              /*|*/ LT(LAYER_MOUSEMACRO,KC_ENT), MT(MOD_RSFT,KC_SPC), MO(LAYER_SYMBOLS), KC_MINS, KC_QUOT, LT(LAYER_MOUSEMACRO,KC_EQUAL)
       ),

//  Q W E R T    Y U I O P
//  A S D F G    H J K L ;
//  Z X C V B    N M , . backslash
//                   - ' =

[LAYER_QWERTY] = LAYOUT(
                        KC_Q, KC_W, KC_E, KC_R, KC_T, __v, /*|*/ __v, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    \
                        KC_A, KC_S, KC_D, KC_F, KC_G, __v, /*|*/ __v, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, \
                        KC_Z, KC_X, KC_C, KC_V, KC_B, __v, /*|*/ __v, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
                        __v,  __v,  __v,  __v,  __v,  __v, /*|*/ __v, __v,  __v,  __v,     __v,    __v      ),

// * 7 8 9 0  | [ ] # !
// + 4 5 6 ~  @ ( ) ^ $
// = 1 2 3 `  & { } % backslash
//   0 .          - ' =

[LAYER_SYMBOLS] = LAYOUT(
                         S(KC_8),   KC_7, KC_8,   KC_9, KC_0,        __v, /*|*/ __v, S(KC_BSLS), KC_LBRC,    KC_RBRC,    S(KC_3),    S(KC_1),    \
                         S(KC_EQL), KC_4, KC_5,   KC_6, S(KC_GRAVE), __v, /*|*/ __v, S(KC_2),    S(KC_9),    S(KC_0),    S(KC_6),    S(KC_4),    \
                         KC_EQL,    KC_1, KC_2,   KC_3, KC_GRAVE,    __v, /*|*/ __v, S(KC_7),    S(KC_LBRC), S(KC_RBRC), S(KC_5),    KC_BSLS,    \
                         __v,       KC_0, KC_DOT, ___,  __v,         __v, /*|*/ __v, __v,        ___,        S(KC_MINS), S(KC_QUOT), S(KC_EQUAL) ),

[LAYER_FNARROWS] = LAYOUT(
                          KC_INS,  KC_F7, KC_F8, KC_F9, KC_F10, __v, /*|*/ __v, KC_HOME, KC_RGHT, KC_END,  KC_PGUP, KC_PSCREEN, \
                          KC_DEL,  KC_F4, KC_F5, KC_F6, KC_F11, __v, /*|*/ __v, KC_LEFT, KC_DOWN, KC_UP,   KC_PGDN, KC_PAUSE,   \
                          KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F12, __v, /*|*/ __v, KC_VOLD, KC_VOLU, KC_MUTE, KC_F13,  KC_F14,     \
                          __v,     __v,   __v,   ___,   __v,    __v, /*|*/ __v, __v,     ___,     __v,     __v,     RESET       ),

[LAYER_MOUSEMACRO] = LAYOUT(
                            DF(LAYER_QWERTY), KC_BTN1, KC_MS_U,           KC_BTN2, KC_WH_U, __v, /*|*/ __v, ___, ___,     ___,     ___,     ___,     \
                            KC_FN0,           KC_MS_L, KC_MS_D,           KC_MS_R, KC_WH_D, __v, /*|*/ __v, ___, ___,     ___,     ___,     ___,     \
                            KC_FN1,           ___,     DF(LAYER_COLEMAK), KC_BTN3, ___,     __v, /*|*/ __v, ___, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, \
                            ___,              ___,     ___,               ___,     ___,     __v, /*|*/ __v, ___, KC_WH_L, KC_WH_R, ___,     ___      ),
};

// Macro definition
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  /*
  // debug
  xprintf("------------\n");
  xprintf("key row: %u\n", record->event.key.row);
  xprintf("key col: %u\n", record->event.key.col);
  xprintf("pressed: %u\n", record->event.pressed);
  */

  switch (id) {
  case ECHOH:
    return (record->event.pressed ?
            MACRO( D(LCTRL), T(C), U(LCTRL), T(E), T(C), T(H), T(O), T(SPC), T(MINS), T(E), T(SPC),
                   D(LSHIFT), T(QUOT), U(LSHIFT), T(BSLS), T(0), T(3), T(3), D(LSHIFT), T(9), U(LSHIFT), T(0), D(LSHIFT), T(QUOT), U(LSHIFT), T(SPC),
                   T(SCLN), T(SPC), T(C), T(L), T(E), T(A), T(R), T(ENT),
                   END) :
            MACRO_NONE);

  case GITCOMMIT:
    return (record->event.pressed ?
            MACRO( D(LCTRL), T(C), U(LCTRL),
                   T(G), T(I), T(T), T(SPC), T(C), T(O), T(M), T(M), T(I), T(T), T(SPC), T(MINS), T(A), T(ENT),
                   END) :
            MACRO_NONE);

    /*
  // ruby -e 'Dir["*"].map{|d|`mv #{d} #{d.split("").shuffle.join}`}'
  case SHUFFLEFILES:
    return (record->event.pressed ?
            MACRO( D(LCTRL), T(C), U(LCTRL), T(R), T(U), T(B), T(Y), T(SPC), T(MINUS), T(E), T(SPC),
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
    */

  }
  return MACRO_NONE;
}


const uint16_t PROGMEM fn_actions[] = {
  // these run action_get_macro() with the respective ids
  [0] = ACTION_MACRO(GITCOMMIT),  // becomes keycode KC_FN0
  [1] = ACTION_MACRO(ECHOH),  // becomes keycode KC_FN1

  // Other examples
  // [0] = ACTION_LAYER_TAP_TOGGLE(LAYER_SYMBOLS),
  // [1] = ACTION_LAYER_TAP_TOGGLE(LAYER_FNARROWS),
  // [0] = ACTION_LAYER_MOMENTARY(LAYER_SYMBOLS),
  // [1] = ACTION_LAYER_MOMENTARY(LAYER_FNARROWS),

  // This runs action_function() below with id == BOOTLOADER
  // [2] = ACTION_FUNCTION(BOOTLOADER),

  // [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  // [4] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT),
  // [5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SPC),
  // [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),
  // [7] = ACTION_MODS_TAP_KEY(MOD_LGUI|MOD_LCTL|MOD_LALT, KC_ESC),
  // [8] = ACTION_LAYER_TAP_KEY(4, KC_EQUAL),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  /* if (id == BOOTLOADER) { */
  /*   bootloader(); */
  /* } */
}
