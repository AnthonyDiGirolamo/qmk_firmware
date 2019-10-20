#ifndef ATREUS_SPLIT_H
#define ATREUS_SPLIT_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
) { \
  { K09, K08, K07, K06, K05, KC_NO, K04, K03, K02, K01, K00, },       \
  { K19, K18, K17, K16, K15, KC_NO, K14, K13, K12, K11, K10, },       \
  { K29, K28, K27, K26, K25, K35,   K24, K23, K22, K21, K20, },       \
  { K3A, K39, K38, K37, K36, K34,   K33, K32, K31, K30, K2A, }        \
}

enum function_id {
  BOOTLOADER,
};

void bootloader(void);

#endif
