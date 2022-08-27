#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 2000
#define IGNORE_MOD_TAP_INTERRUPT
#define ONESHOT_TIMEOUT 5000

// Sugar to automatically prefix `KC_` onto every keycode for cleaner keymaps
#define LAYOUT_KC( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
  L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
                 L41, L42, L43, L44, R41, R42, R43, R44  \
  ) \
  LAYOUT( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L45, KC_##R40, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, \
                                  KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##R41, KC_##R42, KC_##R43, KC_##R44 \
  )

// Sugar to automatically prefix `KC_` onto every keycode for cleaner keymaps
#define LAYOUT_KC_LCAG( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
  L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
                 L41, L42, L43, L44, R41, R42, R43, R44  \
  ) \
  LAYOUT( \
    LCAG(KC_##L00), LCAG(KC_##L01), LCAG(KC_##L02), LCAG(KC_##L03), LCAG(KC_##L04), LCAG(KC_##L05),                     LCAG(KC_##R00), LCAG(KC_##R01), LCAG(KC_##R02), LCAG(KC_##R03), LCAG(KC_##R04), LCAG(KC_##R05), \
    LCAG(KC_##L10), LCAG(KC_##L11), LCAG(KC_##L12), LCAG(KC_##L13), LCAG(KC_##L14), LCAG(KC_##L15),                     LCAG(KC_##R10), LCAG(KC_##R11), LCAG(KC_##R12), LCAG(KC_##R13), LCAG(KC_##R14), LCAG(KC_##R15), \
    LCAG(KC_##L20), LCAG(KC_##L21), LCAG(KC_##L22), LCAG(KC_##L23), LCAG(KC_##L24), LCAG(KC_##L25),                     LCAG(KC_##R20), LCAG(KC_##R21), LCAG(KC_##R22), LCAG(KC_##R23), LCAG(KC_##R24), LCAG(KC_##R25), \
    LCAG(KC_##L30), LCAG(KC_##L31), LCAG(KC_##L32), LCAG(KC_##L33), LCAG(KC_##L34), LCAG(KC_##L35), LCAG(KC_##L45), LCAG(KC_##R40), LCAG(KC_##R30), LCAG(KC_##R31), LCAG(KC_##R32), LCAG(KC_##R33), LCAG(KC_##R34), LCAG(KC_##R35), \
                                  LCAG(KC_##L41), LCAG(KC_##L42), LCAG(KC_##L43), LCAG(KC_##L44), LCAG(KC_##R41), LCAG(KC_##R42), LCAG(KC_##R43), LCAG(KC_##R44) \
  )
