#include "atreus_split.h"
#include "action_layer.h"
#include <print.h>

#ifdef PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#include "ps2.h"
#endif

enum layer_id {
  LAYER_COLEMAK,
  LAYER_QWERTY,
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
  RIGHT_FN_MACRO,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_COLEMAK] = KEYMAP(
  KC_Q,    KC_W,     KC_F,    KC_P,    KC_G,    /*       */       KC_J,    KC_L,    KC_U,     KC_Y,     KC_SCLN,  \
  KC_A,    KC_R,     KC_S,    KC_T,    KC_D,    /*       */       KC_H,    KC_N,    KC_E,     KC_I,     KC_O,     \
  KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    /*       */       KC_K,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  \
  KC_FN7,  KC_LGUI,  KC_TAB,  KC_FN1,  KC_FN6,  KC_FN3,  KC_FN4,  KC_FN5,  KC_FN0,  KC_MINS,  KC_QUOT,  KC_FN8),

// Q  W  E  R  T      Y  U  I     O    P
// A  S  D  F  G      H  J  K     L    SCLN
// Z  X  C  V  B      N  M  COMM  DOT  SLSH

[LAYER_QWERTY] = KEYMAP(
  KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    /*       */       KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     \
  KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    /*       */       KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  \
  KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    /*       */       KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  \
  KC_FN7,  KC_LGUI,  KC_TAB,  KC_FN1,  KC_FN6,  KC_FN3,  KC_FN4,  KC_FN5,  KC_FN0,  KC_MINS,  KC_QUOT,  KC_FN8),

// * 7 8 9 0  | [ ] # !
// + 4 5 6 ~  @ ( ) ^ $
// = 1 2 3 `  & { } % BSLASH
//   0 .          - '

[LAYER_SYMBOLS] = KEYMAP(
  S(KC_8),    KC_7,  KC_8,    KC_9,     KC_0,         /*        */        S(KC_BSLS),  KC_LBRC,     KC_RBRC,     S(KC_3),     S(KC_1),  \
  S(KC_EQL),  KC_4,  KC_5,    KC_6,     S(KC_GRAVE),  /*        */        S(KC_2),     S(KC_9),     S(KC_0),     S(KC_6),     S(KC_4),  \
  KC_EQL,     KC_1,  KC_2,    KC_3,     KC_GRAVE,     /*        */        S(KC_7),     S(KC_LBRC),  S(KC_RBRC),  S(KC_5),     KC_BSLS,  \
  KC_TRNS,    KC_0,  KC_DOT,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     S(KC_MINS),  S(KC_QUOT),  KC_TRNS),

[LAYER_FNARROWS] = KEYMAP(
  KC_INS,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   /*        */        KC_HOME,  KC_RGHT,  KC_END,   KC_PGUP,  KC_PSCR,   \
  KC_DEL,   KC_F4,    KC_F5,    KC_F6,    KC_F11,   /*        */        KC_LEFT,  KC_DOWN,  KC_UP,    KC_PGDN,  KC_PAUSE,  \
  KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F12,   /*        */        KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_F13,   KC_F14,    \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET),

[LAYER_MOUSEMACRO] = KEYMAP(
  KC_FN10,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  /*                      */      KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  \
  KC_FN11,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  /*                      */      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  \
  KC_NO,    KC_NO,    KC_FN9,  KC_BTN3,  KC_NO,    /*                      */      KC_NO,  KC_MS_BTN1,  KC_MS_BTN2,  KC_MS_BTN3,   KC_MS_BTN4,  \
  KC_TRNS,  KC_NO,    KC_NO,    KC_TRNS,    KC_BTN1,  DF(LAYER_NORMAL_MODE),  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,    KC_NO,  KC_FN8),

// Global Normal Mode

[LAYER_NORMAL_MODE] = KEYMAP(
  KC_NO,              LCTL(KC_RIGHT),  KC_NO,                    M(PASTE),       LCTL(KC_HOME),            /*       */      KC_NO,                   KC_RIGHT,  LCTL(KC_Z),     LCTL(KC_C),         KC_NO,            \
  DF(LAYER_COLEMAK),  LCTL(KC_Y),      KC_NO,                    KC_NO,          TG(LAYER_DELETE_MOTION),  /*       */      KC_LEFT,                 KC_DOWN,   KC_UP,          DF(LAYER_COLEMAK),  M(NEWLINEBELOW),  \
  KC_NO,              KC_DEL,          TG(LAYER_CHANGE_MOTION),  M(VISUALMODE),  LCTL(KC_LEFT),            /*       */      KC_NO,                   KC_NO,     KC_NO,          M(DOTREPEAT),       M(SEARCH),        \
  KC_NO,              KC_NO,           KC_NO,                    KC_NO,          MO(LAYER_NORMAL_SHIFT),   KC_ESC,  KC_NO,  MO(LAYER_NORMAL_SHIFT),  KC_NO,     LCTL(S(KC_8)),  KC_NO,              KC_TRNS),
  // need FN8 or TRNS at the end here or LAYER_MOUSEMACRO ends up getting stuck

[LAYER_NORMAL_SHIFT] = KEYMAP(
  KC_NO,               KC_TRNS,  KC_NO,  M(SHIFTPASTE),      LCTL(KC_END),   /*      */      KC_NO,    KC_TRNS,  KC_NO,              KC_NO,                     KC_NO, \
  M(ENDOFLINEAPPEND),  KC_NO,    KC_NO,  KC_NO,              KC_NO,          /*      */      KC_TRNS,  KC_TRNS,  KC_TRNS,            M(BEGINNINGOFLINEINSERT),  M(NEWLINEABOVE),  \
  KC_NO,               KC_NO,    KC_NO,  M(VISUALLINEMODE),  KC_TRNS,        /*      */      KC_NO,    KC_NO,    LCTL(KC_LBRACKET),  LCTL(KC_RBRACKET),         KC_NO,            \
  KC_NO,               KC_NO,    KC_NO,  KC_NO,              KC_TRNS,        KC_NO,  KC_NO,  KC_TRNS,  KC_NO,    LCTL(S(KC_7)),      KC_NO,                     KC_NO),

[LAYER_VISUAL_MODE] = KEYMAP(
  KC_NO,  LCTL(S(KC_RIGHT)),  KC_NO,            M(VISUALPASTE),  KC_NO,                   /*              */      KC_NO,                   S(KC_RIGHT),  KC_NO,          M(VISUALYANK),  KC_NO,  \
  KC_NO,  KC_NO,              KC_NO,            KC_NO,           M(VISUALDELETE),         /*              */      S(KC_LEFT),              S(KC_DOWN),   S(KC_UP),       KC_NO,          KC_NO,  \
  KC_NO,  M(VISUALDELETE),    M(VISUALCHANGE),  M(VISUALMODE),   LCTL(S(KC_LEFT)),        /*              */      KC_NO,                   KC_NO,        KC_NO,          KC_NO,          KC_NO,  \
  KC_NO,  KC_NO,              KC_NO,            KC_NO,           MO(LAYER_VISUAL_SHIFT),  M(VISUALMODE),  KC_NO,  MO(LAYER_VISUAL_SHIFT),  KC_NO,        LCTL(S(KC_8)),  KC_NO,          KC_NO),

[LAYER_VISUAL_SHIFT] = KEYMAP(
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    /*      */      KC_NO,    KC_NO,  KC_NO,              KC_NO,              KC_NO,  \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    /*      */      KC_NO,    KC_NO,  KC_NO,              KC_NO,              KC_NO,  \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    /*      */      KC_NO,    KC_NO,  LCTL(KC_LBRACKET),  LCTL(KC_RBRACKET),  KC_NO,  \
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  LCTL(S(KC_7)),      KC_NO,              KC_NO),

[LAYER_DELETE_MOTION] = KEYMAP(
  KC_NO,  M(DELETEWORD),  KC_NO,  KC_NO,  KC_NO,          /*                        */      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \
  KC_NO,  KC_NO,          KC_NO,  KC_NO,  M(DELETELINE),  /*                        */      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \
  KC_NO,  KC_NO,          KC_NO,  KC_NO,  KC_NO,          /*                        */      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \
  KC_NO,  KC_NO,          KC_NO,  KC_NO,  KC_TRNS,        TG(LAYER_DELETE_MOTION),  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO),

/* [LAYER_DELETE_INNER_MOTION] = KEYMAP( */
/*   KC_NO,  M(DELETEINNERWORD),  KC_NO,  KC_NO,  KC_NO,    /\*                              *\/      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \ */
/*   KC_NO,  KC_NO,               KC_NO,  KC_NO,  KC_NO,    /\*                              *\/      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \ */
/*   KC_NO,  KC_NO,               KC_NO,  KC_NO,  KC_NO,    /\*                              *\/      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \ */
/*   KC_NO,  KC_NO,               KC_NO,  KC_NO,  KC_TRNS,  TG(LAYER_DELETE_INNER_MOTION),  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO), */

[LAYER_CHANGE_MOTION] = KEYMAP(
  KC_NO,  M(CHANGEINNERWORD),  KC_NO,          KC_NO,  KC_NO,    /*                        */      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \
  KC_NO,  KC_NO,               KC_NO,          KC_NO,  KC_NO,    /*                        */      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \
  KC_NO,  KC_NO,               M(CHANGELINE),  KC_NO,  KC_NO,    /*                        */      KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  \
  KC_NO,  KC_NO,               KC_NO,          KC_NO,  KC_TRNS,  TG(LAYER_CHANGE_MOTION),  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO),

};

enum mode_ids {
  VISUALMODE_BIT,
  LASTDELETE_ENTIRE_LINE_BIT,
};

// Macro definition
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mode;
  static uint8_t last_action;
  static uint8_t last_action_count;
  static uint16_t last_millis;

  // check if bit is set
  // if (mode & _BV(LASTDELETE_ENTIRE_LINE_BIT))
  // set bit
  // mode |= _BV(LASTDELETE_ENTIRE_LINE_BIT);
  // clear bit
  // mode &= ~(_BV(LASTDELETE_ENTIRE_LINE_BIT));

  if (id == last_action && record->event.time-last_millis < 200) {
    last_action_count++;
  }
  else {
    last_action_count = 0;
  }

  if (id == DOTREPEAT && last_action > 0)
    id = last_action;

  xprintf("----action_get_macro----\n");
  xprintf("%d\n", last_action_count);
  xprintf("%d\n", record->event.time-last_millis);
  xprintf("------------\n");

  xprintf("key row: %u\n", record->event.key.row);
  xprintf("key col: %u\n", record->event.key.col);
  xprintf("pressed: %u\n", record->event.pressed);
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

  xprintf("layer: %08lX(%u)\n", layer_state, biton32(layer_state));


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

  /*
  case GITCOMMIT:
    return (record->event.pressed ?
            MACRO( D(LCTRL), T(C), U(LCTRL),
                   T(G), T(I), T(T), T(SPC), T(C), T(O), T(M), T(M), T(I), T(T), T(SPC), T(MINS), T(A), T(ENT),
                   END) :
            MACRO_NONE);
  */

  case RIGHT_FN_MACRO:
    if (record->event.pressed) { // on press
      // normal modifier hold
      layer_on(LAYER_SYMBOLS);
    } else { // on release
      // normal modifier release
      layer_off(LAYER_SYMBOLS);

      // if double tap on right FN key - lock LAYER_MOUSEMACRO
      if (last_action_count >= 3 && last_action == RIGHT_FN_MACRO) {
        layer_on(LAYER_MOUSEMACRO);
      }
      else {
        layer_off(LAYER_MOUSEMACRO);
      }
    }
    last_action = id;
    break;

  }

  // save last event time
  last_millis = record->event.time;
  return MACRO_NONE;
}


const uint16_t PROGMEM fn_actions[] = {
  /* [0] = ACTION_LAYER_TAP_TOGGLE(2), // KC_FN0 */
  /* [1] = ACTION_LAYER_TAP_TOGGLE(3), // KC_FN1 */
  /* [0] = ACTION_LAYER_MOMENTARY(2), // KC_FN0 */
  /* [1] = ACTION_LAYER_MOMENTARY(3), // KC_FN1 */

  [0] = ACTION_MACRO(RIGHT_FN_MACRO), // KC_FN0
  [1] = ACTION_LAYER_MOMENTARY(3), // KC_FN1
  [2] = ACTION_FUNCTION(BOOTLOADER), // KC_FN2

  [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC), // KC_FN3
  [4] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT), // KC_FN4
  [5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SPC), // KC_FN5
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC), // KC_FN6

  [7] = ACTION_MODS_TAP_KEY(MOD_LGUI|MOD_LCTL|MOD_LALT, KC_ESC), // KC_FN7
  [8] = ACTION_LAYER_TAP_KEY(4, KC_ENT), // KC_FN8

  [9] = ACTION_DEFAULT_LAYER_SET(0), // KC_FN9 -> KC_C: LAYER_COLEMAK
  [10] = ACTION_DEFAULT_LAYER_SET(1), // KC_FN10 -> KC_Q: LAYER_QWERTY

  [11] = ACTION_MACRO(ECHOH), // KC_FN11
  /* [12] = ACTION_MACRO(GITCOMMIT), // KC_FN12 */
};

/*
// process all keys
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  xprintf("----process_record_user----\n");
  xprintf("key row: %u\n", record->event.key.row);
  xprintf("key col: %u\n", record->event.key.col);
  xprintf("pressed: %u\n", record->event.pressed);
  xprintf("------------\n");

  switch (keycode) {
    case FOO:
      if (record->event.pressed) {
        // Do something when pressed
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case KC_ENTER:
      // Play a tone when enter is pressed
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_qwerty);
      }
      return true; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }

  return true; // Process all other keycodes normally
}
*/

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  /* if (id == BOOTLOADER) { */
  /*   bootloader(); */
  /* } */
  xprintf("----action_function----\n");
  /* xprintf("%d\n", record->event.time); */
  /* xprintf("------------\n"); */
  xprintf("key row: %u\n", record->event.key.row);
  xprintf("key col: %u\n", record->event.key.col);
  xprintf("pressed: %u\n", record->event.pressed);
  xprintf("------------\n");

}

/*
void ps2_mouse_task_user(report_mouse_t *mouse_report, uint16_t time) {
  static uint16_t last_mouse_millis;
  static uint8_t mouse_layer_on = 0;

  if (mouse_report->x || mouse_report->y || mouse_report->v || mouse_report->h) {
    if (time-last_mouse_millis < 1000 && mouse_layer_on == 0) {
      xprintf("mouse layer on: time %d %d\n", time-last_mouse_millis, mouse_layer_on);
      layer_on(LAYER_MOUSEMACRO);
      mouse_layer_on = 1;
    }

    // save last mouse move event time
    last_mouse_millis = time;
  }
  else if (time-last_mouse_millis >= 1000 && mouse_layer_on == 1) {
    xprintf("mouse layer off: time %d %d\n", time-last_mouse_millis, mouse_layer_on);
    layer_off(LAYER_MOUSEMACRO);
    mouse_layer_on = 0;
  }
}
*/

#ifdef PS2_MOUSE_ENABLE
  void ps2_mouse_init_user() {
      uint8_t rcv;

      // set TrackPoint sensitivity
      PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2");
      PS2_MOUSE_SEND(0x81, "tpsens: 0x81");
      PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A");
      PS2_MOUSE_SEND(0xD0, "tpsens: 0x59"); // setting: 00 to FF?

      // set TrackPoint Negative Inertia factor
      PS2_MOUSE_SEND(0xE2, "tpnegin: 0xE2");
      PS2_MOUSE_SEND(0x81, "tpnegin: 0x81");
      PS2_MOUSE_SEND(0x4D, "tpnegin: 0x4D");
      PS2_MOUSE_SEND(0x04, "tpnegin: 0x06"); // setting: 00 to ?

      // set TrackPoint speed
      // (transfer function upper plateau speed)
      PS2_MOUSE_SEND(0xE2, "tpsp: 0xE2");
      PS2_MOUSE_SEND(0x81, "tpsp: 0x81");
      PS2_MOUSE_SEND(0x60, "tpsp: 0x60");
      PS2_MOUSE_SEND(0x79, "tpsp: 0x61"); // setting: 0 to FF?

      // inquire pts status
      rcv = ps2_host_send(0xE2);
      rcv = ps2_host_send(0x2C);
      rcv = ps2_host_recv_response();
      if ((rcv & 1) == 1) {
        // if on, disable pts
        rcv = ps2_host_send(0xE2);
        rcv = ps2_host_send(0x47);
        rcv = ps2_host_send(0x2C);
        rcv = ps2_host_send(0x01);
      }
  }
#endif
