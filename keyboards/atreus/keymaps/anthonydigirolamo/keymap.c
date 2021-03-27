#include QMK_KEYBOARD_H

enum layer_id {
  LAYER_COLEMAK,
  LAYER_QWERTY,
  LAYER_GAMING,
  LAYER_SYMBOLS,
  LAYER_FNARROWS,
  LAYER_MOUSEMACRO,
  LAYER_NORMAL_MODE,
  LAYER_NORMAL_SHIFT,
  LAYER_VISUAL_MODE,
  LAYER_VISUAL_SHIFT,
  LAYER_DELETE_MOTION,
  LAYER_DELETE_INNER_MOTION,
  LAYER_CHANGE_MOTION,
};

enum macro_id {
  ECHOH,
  SHUFFLEFILES,
  GITCOMMIT,
  DELETELINE,
  DELETEINNERWORD,
  DELETEWORD,
  CHANGELINE,
  CHANGEINNERWORD,
  PASTE,
  SHIFTPASTE,
  SEARCH,
  NEWLINEABOVE,
  NEWLINEBELOW,
  BEGINNINGOFLINEINSERT,
  ENDOFLINEAPPEND,
  VISUALMODE,
  VISUALLINEMODE,
  VISUALDELETE,
  VISUALPASTE,
  VISUALCHANGE,
  VISUALYANK,
  VISUALUNINDENT,
  VISUALINDENT,
  UNINDENT,
  INDENT,
  DOTREPEAT,
};

#define HYPER_ESC MT(MOD_LGUI|MOD_LCTL|MOD_LALT, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_COLEMAK] = LAYOUT(
  KC_Q,      KC_W,    KC_F,   KC_P,               KC_G,                 /*                   */                   KC_J,                KC_L,              KC_U,    KC_Y,    KC_SCLN, \
  KC_A,      KC_R,    KC_S,   KC_T,               KC_D,                 /*                   */                   KC_H,                KC_N,              KC_E,    KC_I,    KC_O,    \
  KC_Z,      KC_X,    KC_C,   KC_V,               KC_B,                 /*                   */                   KC_K,                KC_M,              KC_COMM, KC_DOT,  KC_SLSH, \
  HYPER_ESC, KC_LGUI, KC_TAB, MO(LAYER_FNARROWS), MT(MOD_LSFT,KC_BSPC), MT(MOD_LCTL,KC_ESC), MT(MOD_LALT,KC_ENT), MT(MOD_RSFT,KC_SPC), MO(LAYER_SYMBOLS), KC_MINS, KC_QUOT, LT(LAYER_MOUSEMACRO,KC_ENT)),

// Q  W  E  R  T      Y  U  I     O    P
// A  S  D  F  G      H  J  K     L    SCLN
// Z  X  C  V  B      N  M  COMM  DOT  SLSH

[LAYER_QWERTY] = LAYOUT(
                        KC_Q, KC_W, KC_E, KC_R, KC_T, /*   */   KC_Y, KC_U, KC_I,    KC_O,   KC_P,    \
                        KC_A, KC_S, KC_D, KC_F, KC_G, /*   */   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, \
                        KC_Z, KC_X, KC_C, KC_V, KC_B, /*   */   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
                        __v,  __v,  __v,  __v,  __v,  __v, __v, __v,  __v,  __v,     __v,    __v      ),

[LAYER_GAMING] = LAYOUT(
                        KC_TAB,    KC_Q, KC_W, KC_E, KC_R,   /*        */       KC_Y, KC_U, KC_I,    KC_O,   KC_P,    \
                        KC_LSHIFT, KC_A, KC_S, KC_D, KC_F,   /*        */       KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, \
                        KC_1,      KC_Z, KC_X, KC_C, KC_V,   /*        */       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
                        KC_ESC,    KC_2, KC_3, KC_4, KC_SPC, KC_LCTRL, KC_LALT, __v,  __v,  __v,     __v,    __v      ),

// * 7 8 9 0  | [ ] # !
// + 4 5 6 ~  @ ( ) ^ $
// = 1 2 3 `  & { } % BSLASH
//   0 .          - '

[LAYER_SYMBOLS] = LAYOUT(
                         S(KC_8),   KC_7, KC_8,   KC_9, KC_0,        /*   */   S(KC_BSLS), KC_LBRC,    KC_RBRC,    S(KC_3),    S(KC_1), \
                         S(KC_EQL), KC_4, KC_5,   KC_6, S(KC_GRAVE), /*   */   S(KC_2),    S(KC_9),    S(KC_0),    S(KC_6),    S(KC_4), \
                         KC_EQL,    KC_1, KC_2,   KC_3, KC_GRAVE,    /*   */   S(KC_7),    S(KC_LBRC), S(KC_RBRC), S(KC_5),    KC_BSLS, \
                         __v,       KC_0, KC_DOT, __v,  __v,         __v, __v, __v,        __v,        S(KC_MINS), S(KC_QUOT), __v),

[LAYER_FNARROWS] = LAYOUT(
                          KC_INS,  KC_F7, KC_F8, KC_F9, KC_F10, /*   */   KC_HOME, KC_RGHT, KC_END,  KC_PGUP, KC_PSCR,  \
                          KC_DEL,  KC_F4, KC_F5, KC_F6, KC_F11, /*   */   KC_LEFT, KC_DOWN, KC_UP,   KC_PGDN, KC_PAUSE, \
                          KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F12, /*   */   KC_VOLD, KC_VOLU, KC_MUTE, KC_F13,  KC_F14,   \
                          __v,     __v,   __v,   __v,   __v,    __v, __v, __v,     __v,     __v,     __v,     RESET),

[LAYER_MOUSEMACRO] = LAYOUT(
                            DF(LAYER_QWERTY), KC_BTN1, KC_MS_U,           KC_BTN2, KC_WH_U,          /*                     */   ___, ___,     ___,     ___,     ___,     \
                            ___,              KC_MS_L, KC_MS_D,           KC_MS_R, KC_WH_D,          /*                     */   ___, ___,     KC_FN1,  ___,     ___,     \
                            ___,              ___,     DF(LAYER_COLEMAK), KC_BTN3, DF(LAYER_GAMING), /*                     */   ___, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, \
                            __v,              ___,     ___,               ___,     KC_BTN1,          DF(LAYER_NORMAL_MODE), ___, ___, KC_WH_L, KC_WH_R, ___,     LT(LAYER_MOUSEMACRO,KC_ENT)),

// Global Normal Mode

[LAYER_NORMAL_MODE] = LAYOUT(
                             ___,               LCTL(KC_RIGHT), ___,                     M(PASTE),      ___,                     /*      */   ___,                    KC_RIGHT, LCTL(KC_Z),    LCTL(KC_C),        ___,             \
                             DF(LAYER_COLEMAK), LCTL(KC_Y),     ___,                     ___,           TG(LAYER_DELETE_MOTION), /*      */   KC_LEFT,                KC_DOWN,  KC_UP,         DF(LAYER_COLEMAK), M(NEWLINEBELOW), \
                             ___,               KC_DEL,         TG(LAYER_CHANGE_MOTION), M(VISUALMODE), LCTL(KC_LEFT),           /*      */   ___,                    ___,      ___,           M(DOTREPEAT),      M(SEARCH),       \
                             ___,               ___,            ___,                     ___,           MO(LAYER_NORMAL_SHIFT),  KC_ESC, ___, MO(LAYER_NORMAL_SHIFT), ___,      LCTL(S(KC_8)), ___,               __v),
// need FN8 or TRNS at the end here or LAYER_MOUSEMACRO ends up getting stuck

[LAYER_NORMAL_SHIFT] = LAYOUT(
                              ___,                __v, ___, M(SHIFTPASTE),     ___, /*   */   ___, __v, ___,               ___,                      ___,             \
                              M(ENDOFLINEAPPEND), ___, ___, ___,               ___, /*   */   __v, __v, __v,               M(BEGINNINGOFLINEINSERT), M(NEWLINEABOVE), \
                              ___,                ___, ___, M(VISUALLINEMODE), __v, /*   */   ___, ___, LCTL(KC_LBRACKET), LCTL(KC_RBRACKET),        ___,             \
                              ___,                ___, ___, ___,               __v, ___, ___, __v, ___, LCTL(S(KC_7)),     ___,                      ___),

[LAYER_VISUAL_MODE] = LAYOUT(
                             ___, LCTL(S(KC_RIGHT)), ___,             M(VISUALPASTE), ___,                    /*             */   ___,                    S(KC_RIGHT), ___,           M(VISUALYANK), ___, \
                             ___, ___,               ___,             ___,            M(VISUALDELETE),        /*             */   S(KC_LEFT),             S(KC_DOWN),  S(KC_UP),      ___,           ___, \
                             ___, M(VISUALDELETE),   M(VISUALCHANGE), M(VISUALMODE),  LCTL(S(KC_LEFT)),       /*             */   ___,                    ___,         ___,           ___,           ___, \
                             ___, ___,               ___,             ___,            MO(LAYER_VISUAL_SHIFT), M(VISUALMODE), ___, MO(LAYER_VISUAL_SHIFT), ___,         LCTL(S(KC_8)), ___,           ___),

[LAYER_VISUAL_SHIFT] = LAYOUT(
                              ___, ___, ___, ___, ___, /*   */   ___, ___, ___,               ___,               ___, \
                              ___, ___, ___, ___, ___, /*   */   ___, ___, ___,               ___,               ___, \
                              ___, ___, ___, ___, ___, /*   */   ___, ___, LCTL(KC_LBRACKET), LCTL(KC_RBRACKET), ___, \
                              ___, ___, ___, ___, __v, ___, ___, __v, ___, LCTL(S(KC_7)),     ___,               ___),

[LAYER_DELETE_MOTION] = LAYOUT(
                               ___, M(DELETEWORD), ___, ___, ___,           /*                       */   ___, ___, ___, ___, ___, \
                               ___, ___,           ___, ___, M(DELETELINE), /*                       */   ___, ___, ___, ___, ___, \
                               ___, ___,           ___, ___, ___,           /*                       */   ___, ___, ___, ___, ___, \
                               ___, ___,           ___, ___, __v,           TG(LAYER_DELETE_MOTION), ___, __v, ___, ___, ___, ___),

/* [LAYER_DELETE_INNER_MOTION] = LAYOUT( */
/* ___, M(DELETEINNERWORD), ___, ___, ___, /\*                            *\/  ___, ___, ___, ___, ___,  \ */
/* ___, ___,                ___, ___, ___, /\*                            *\/  ___, ___, ___, ___, ___,  \ */
/* ___, ___,                ___, ___, ___, /\*                            *\/  ___, ___, ___, ___, ___,  \ */
/* ___, ___,                ___, ___, __v, TG(LAYER_DELETE_INNER_MOTION), ___, __v, ___, ___, ___, ___), */

[LAYER_CHANGE_MOTION] = LAYOUT(
                               ___, M(CHANGEINNERWORD), ___,           ___, ___, /*                       */   ___, ___, ___, ___, ___, \
                               ___, ___,                ___,           ___, ___, /*                       */   ___, ___, ___, ___, ___, \
                               ___, ___,                M(CHANGELINE), ___, ___, /*                       */   ___, ___, ___, ___, ___, \
                               ___, ___,                ___,           ___, __v, TG(LAYER_CHANGE_MOTION), ___, __v, ___, ___, ___, ___),

};

enum mode_ids {
  VISUALMODE_BIT,
  LASTDELETE_ENTIRE_LINE_BIT,
};

// Macro definition
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mode;
  static uint8_t last_action;

  // check if bit is set
  // if (mode & _BV(LASTDELETE_ENTIRE_LINE_BIT))
  // set bit
  // mode |= _BV(LASTDELETE_ENTIRE_LINE_BIT);
  // clear bit
  // mode &= ~(_BV(LASTDELETE_ENTIRE_LINE_BIT));

  xprintf("------------\n");

  xprintf("mode bits: ");
  xprintf("%d%d%d%d%d%d%d%d",
          (mode & 0x080 ? 1 : 0), \
          (mode & 0x040 ? 1 : 0), \
          (mode & 0x020 ? 1 : 0), \
          (mode & 0x010 ? 1 : 0), \
          (mode & 0x08 ? 1 : 0), \
          (mode & 0x04 ? 1 : 0), \
          (mode & 0x02 ? 1 : 0), \
          (mode & 0x01 ? 1 : 0));
  xprintf("\n");

  xprintf("key row: %u\n", record->event.key.row);
  xprintf("key col: %u\n", record->event.key.col);
  xprintf("pressed: %u\n", record->event.pressed);

  xprintf("layer: %08lX(%u)\n", layer_state, biton32(layer_state));

  if (id == DOTREPEAT && last_action > 0)
    id = last_action;

  switch (id) {
  case VISUALMODE:
    if (record->event.pressed) { // on press
      mode ^= _BV(VISUALMODE_BIT); // toggle first bit
      xprintf("visual [mode: %u]\n", mode & _BV(VISUALMODE_BIT));

      if (mode & _BV(VISUALMODE_BIT)) { // if first bit is set
        layer_on(LAYER_VISUAL_MODE);
        return MACRO( D(LSHIFT), T(RIGHT), U(LSHIFT), END); // start the selection
      }
      else {
        layer_off(LAYER_VISUAL_MODE);
        return MACRO( T(LEFT), END); // clear the selection
      }
    } else { // on release
      // nothing
    }
    break;

  case VISUALLINEMODE:
    if (record->event.pressed) { // on press
      if (mode & _BV(VISUALMODE_BIT)) { // if first bit is set
      }
      else {
        // select the first line
        return MACRO( T(HOME), D(LSHIFT), T(DOWN), U(LSHIFT), END);
      }
    } else { // on release
      mode |= _BV(VISUALMODE_BIT); // turn on visual mode
      xprintf("visual line [mode: %u]\n", mode & _BV(VISUALMODE_BIT));

      layer_off(LAYER_NORMAL_SHIFT); // the layer that VISUALLINEMODE is invoked from
      layer_on(LAYER_VISUAL_MODE);
    }
    break;

  case VISUALCHANGE:
    if (record->event.pressed) { // on press
      // nothing
    } else { // on release
      mode &= ~(_BV(VISUALMODE_BIT)); // turn off visual mode
      xprintf("visual [mode: %u]\n", mode & _BV(VISUALMODE_BIT));

      layer_off(LAYER_VISUAL_MODE);
      default_layer_set(LAYER_COLEMAK); // exit normal mode
      mode &= ~(_BV(LASTDELETE_ENTIRE_LINE_BIT)); // copied text is not an entire line
      return MACRO( D(LCTRL), T(X), U(LCTRL), END); // cut the selection
    }
    break;

  case VISUALYANK:
    if (record->event.pressed) { // on press
      // nothing
    } else { // on release
      mode &= ~(_BV(VISUALMODE_BIT)); // turn off visual mode
      xprintf("visual [mode: %u]\n", mode & _BV(VISUALMODE_BIT));

      layer_off(LAYER_VISUAL_MODE);
      return MACRO( D(LCTRL), T(C), U(LCTRL), END); // copy the selection
    }
    break;

  case VISUALDELETE:
    if (record->event.pressed) { // on press
      // nothing
    } else { // on release
      // must perform action on release otherwise the release will trigger the normal layer action
      mode &= ~(_BV(VISUALMODE_BIT)); // turn off visual mode
      xprintf("visual [mode: %u]\n", mode & _BV(VISUALMODE_BIT));

      layer_off(LAYER_VISUAL_MODE);
      return MACRO( D(LCTRL), T(X), U(LCTRL), END); // cut the selection
    }
    break;

  case VISUALPASTE:
    if (record->event.pressed) { // on press
      // nothing
    } else { // on release
      mode &= ~(_BV(VISUALMODE_BIT)); // turn off visual mode
      xprintf("visual [mode: %u]\n", mode & _BV(VISUALMODE_BIT));

      layer_off(LAYER_VISUAL_MODE);
      return MACRO( D(LCTRL), T(V), U(LCTRL), END); // paste the selection
    }
    break;

  case VISUALUNINDENT:
    if (record->event.pressed) { // on press
      return MACRO( D(LCTRL), T(LBRC), U(LCTRL), END);
    } else { // on release
      // nothing
    }
    break;

  case VISUALINDENT:
    if (record->event.pressed) { // on press
      return MACRO( D(LCTRL), T(RBRC), U(LCTRL), END);
    } else { // on release
      // nothing
    }
    break;

  case UNINDENT:
    last_action = id;
    if (record->event.pressed) { // on press
      return MACRO( D(LCTRL), T(LBRC), U(LCTRL), END);
    } else { // on release
      // nothing
    }
    break;

  case INDENT:
    last_action = id;
    if (record->event.pressed) { // on press
      return MACRO( D(LCTRL), T(RBRC), U(LCTRL), END);
    } else { // on release
      // nothing
    }
    break;

  case BEGINNINGOFLINEINSERT:
    if (record->event.pressed) { // on press
      return MACRO( T(HOME), END);
    } else { // on release
      layer_off(LAYER_NORMAL_SHIFT); // untoggle
      default_layer_set(LAYER_COLEMAK); // exit normal mode
    }
    break;

  case ENDOFLINEAPPEND:
    if (record->event.pressed) { // on press
      return MACRO( T(END), END);
    } else { // on release
      layer_off(LAYER_NORMAL_SHIFT); // untoggle
      default_layer_set(LAYER_COLEMAK); // exit normal mode
    }
    break;

  case NEWLINEABOVE:
    if (record->event.pressed) { // on press
      return MACRO( T(HOME), T(ENTER), T(UP), END);
    } else { // on release
      layer_off(LAYER_NORMAL_SHIFT); // untoggle
      default_layer_set(LAYER_COLEMAK); // exit normal mode
    }
    break;

  case NEWLINEBELOW:
    if (record->event.pressed) { // on press
      return MACRO( T(END), T(ENTER), END);
    } else { // on release
      default_layer_set(LAYER_COLEMAK); // exit normal mode
    }
    break;

  case SEARCH:
    if (record->event.pressed) { // on press
      return MACRO( D(LCTL), T(F), U(LCTL), END);
    } else { // on release
      default_layer_set(LAYER_COLEMAK); // exit normal mode
    }
    break;

  case CHANGELINE:
    if (record->event.pressed) { // on press
      return MACRO( T(HOME), D(LSHIFT), T(END), U(LSHIFT),
                    D(LCTL), T(X), U(LCTL),
                    END);
    } else { // on release
      layer_off(LAYER_CHANGE_MOTION); // untoggle
      default_layer_set(LAYER_COLEMAK); // exit normal mode
    }
    break;

  case CHANGEINNERWORD:
    if (record->event.pressed) { // on press
      return MACRO( D(LCTL), T(LEFT),
                    D(LSHIFT), T(RIGHT), U(LCTL),
                    // T(LEFT),
                    U(LSHIFT),
                    D(LCTL), T(X), U(LCTL),
                    END);
    } else { // on release
      layer_off(LAYER_CHANGE_MOTION); // untoggle
      default_layer_set(LAYER_COLEMAK); // exit normal mode
      mode &= ~(_BV(LASTDELETE_ENTIRE_LINE_BIT)); // copied text is not an entire line
    }
    break;

  case DELETELINE:
    last_action = id;
    if (record->event.pressed) { // on press
      // select the first line and cut
      return MACRO( T(HOME), D(LSHIFT), T(DOWN), U(LSHIFT),
                    D(LCTL), T(X), U(LCTL),
                    END);
    } else { // on release
      layer_off(LAYER_DELETE_MOTION); // untoggle
      mode |= _BV(LASTDELETE_ENTIRE_LINE_BIT); // flag as entire line cut
    }
    break;

  case PASTE:
    last_action = id;
    if (record->event.pressed) { // on press
      if (mode & _BV(LASTDELETE_ENTIRE_LINE_BIT)) { // if last delete/yank was the whole line
        return MACRO( T(HOME), T(DOWN), D(LCTL), T(V), U(LCTL), // move down one line then paste
                      // W(100),
                      // T(LEFT),
                      END);
      }
      else {
        return MACRO( D(LCTL), T(V), U(LCTL),
                      END);
      }
    } else { // on release
      // nothing
    }
    break;

  case SHIFTPASTE:
    last_action = id;
    if (record->event.pressed) { // on press
      if (mode & _BV(LASTDELETE_ENTIRE_LINE_BIT)) { // if last delete/yank was the whole line
        return MACRO( T(HOME), D(LCTL), T(V), U(LCTL),
                      // W(100),
                      // T(LEFT),
                      END);
      }
      else {
        return MACRO( D(LCTL), T(V), U(LCTL),
                      END);
      }
    } else { // on release
      // nothing
    }
    break;

  case DELETEWORD:
    last_action = id;
    if (record->event.pressed) { // on press
      return MACRO( D(LCTL), D(LSHIFT), T(RIGHT), U(LCTL), U(LSHIFT),
                    D(LCTL), T(X), U(LCTL),
                    END);
    } else { // on release
      layer_off(LAYER_DELETE_MOTION); // untoggle
      mode &= ~(_BV(LASTDELETE_ENTIRE_LINE_BIT)); // copied text is not an entire line
    }
    break;

  case DELETEINNERWORD:
    last_action = id;
    if (record->event.pressed) { // on press
      return MACRO( D(LCTL), T(LEFT),
                    D(LSHIFT), T(RIGHT), U(LCTL),
                    // T(LEFT),
                    U(LSHIFT),
                    D(LCTL), T(X), U(LCTL),
                    END);
    } else { // on release
      // layer_off(LAYER_DELETE_INNER_MOTION); // untoggle
      layer_off(LAYER_DELETE_MOTION); // untoggle
      mode &= ~(_BV(LASTDELETE_ENTIRE_LINE_BIT)); // copied text is not an entire line
    }
    break;

  case ECHOH:
    return (record->event.pressed ?
            MACRO( D(LCTRL), T(C), U(LCTRL), T(E), T(C), T(H), T(O), T(SPC), T(MINS), T(E), T(SPC),
                   D(LSHIFT), T(QUOT), U(LSHIFT), T(BSLS), T(0), T(3), T(3), D(LSHIFT), T(9), U(LSHIFT), T(0), D(LSHIFT), T(QUOT), U(LSHIFT), T(SPC),
                   T(SCLN), T(SPC), T(C), T(L), T(E), T(A), T(R), T(ENT),
                   END) :
            MACRO_NONE);

    /*
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
    /* ruby -e 'Dir["*"].map{|d|`mv #{d} #{d.split("").shuffle.join}`}' */

  case GITCOMMIT:
    return (record->event.pressed ?
            MACRO( D(LCTRL), T(C), U(LCTRL),
                   T(G), T(I), T(T), T(SPC), T(C), T(O), T(M), T(M), T(I), T(T), T(SPC), T(MINS), T(A), T(ENT),
                   END) :
            MACRO_NONE);

  }
  return MACRO_NONE;
}


const uint16_t PROGMEM fn_actions[] = {
  // these run action_get_macro() with the respective ids
  [0] = ACTION_MACRO(GITCOMMIT),  // becomes keycode KC_FN0
  [1] = ACTION_MACRO(ECHOH),  // becomes keycode KC_FN1
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // if (id == BOOTLOADER) {
  // bootloader();
  // }
}
