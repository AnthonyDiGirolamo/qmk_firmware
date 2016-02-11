#ifndef ATREUS_HALF_H
#define ATREUS_HALF_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
      k00, k01, k02, k03, k04, \
      k10, k11, k12, k13, k14, \
      k20, k21, k22, k23, k24, k25, \
      k30, k31, k32, k33, k34 \
) \
{ \
    { k00, k01, k02, k03, k04, KC_NO }, \
    { k10, k11, k12, k13, k14, KC_NO }, \
    { k20, k21, k22, k23, k24, k25,  }, \
    { k30, k31, k32, k33, k34, KC_NO } \
}

void * matrix_init_user(void);
void * matrix_scan_user(void);

#endif
