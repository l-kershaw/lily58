#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Aliases
#define KC_ KC_TRNS
#define KC_xx KC_NO
#define KC_PND KC_HASH              // Alias for UK keyboards

#define KC_OSLA OSM(MOD_LALT)           // One shot modifiers
#define KC_OSLG OSM(MOD_LGUI)
#define KC_OSLC OSM(MOD_LCTL)
#define KC_OSLS OSM(MOD_LSFT)
#define KC_OSRA OSM(MOD_RALT)

#define KC_LOWR MO(_LOWER)          // Lower layer
#define KC_RAIS MO(_RAISE)          // Raise layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,                         xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  Q   ,  W   ,  E   ,  R   ,  T   ,                         Y   ,  U   ,  I   ,  O   ,  P   ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  A   ,  S   ,  D   ,  F   ,  G   ,                         H   ,  J   ,  K   ,  L   , SCLN ,  xx  ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
          xx  ,  Z   ,  X   ,  C   ,  V   ,  B   ,  xx ,            xx  ,  N   ,  M   , COMM , DOT  , SLSH ,  xx  ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                            xx  ,  xx  , LSFT ,  LOWR  ,             RAIS  , SPC  ,  xx ,  xx
    //                   +------+------+------+------/              \------+------+------+------+
),

[_LOWER] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,                         xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  , ESC  ,  xx  ,  xx  ,  xx  , TAB  ,                        HOME , PGDN , PGUP , END  , VOLU ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  , OSLA , OSLG , OSLC , OSLS , OSRA ,                        LEFT , DOWN ,  UP  , RGHT , VOLD ,  xx  ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
          xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,           xx  , BSPC , DEL  , MPRV , MPLY , MNXT ,  xx ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                            xx  ,  xx  ,  xx  ,       ,                    ,  ENT ,  xx  ,  xx
    //                   +------+------+------+------/              \------+------+------+------+
),

[_RAISE] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,                         xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  1   ,  2   ,  3   ,  4   ,  5   ,                         6   ,  7   ,  8   ,  9   ,  0   ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  , LABK ,  AT  , LPRN , LBRC , LCBR ,                        EQL  , QUES , QUOT , PLUS , NUBS ,  xx  ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
          xx  , RABK , ASTR , RPRN , RBRC , RCBR ,  xx  ,           xx  , UNDS , EXLM , DQUO , MINS , SLSH ,  xx  ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                            xx  ,  xx  ,  xx  ,       ,                    ,  xx  ,  xx  ,  xx
    //                   +------+------+------+------/              \------+------+------+------+
),

[_ADJUST] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,                         xx  ,  xx  ,  xx  ,  xx  ,  xx  ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  ,  F1  ,  F2  ,  F3  ,  F4  ,  F5  ,                         F6  ,  F7  ,  F8  ,  F9  , F10  ,  xx  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
          xx  , OSLA , OSLG , OSLC , OSLS , OSRA ,                        F11  , F12  ,  xx  ,  xx  ,  xx  ,  xx  ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
          xx  , GRV  , PIPE , AMPR , NUHS , PERC ,  xx  ,           xx  , DLR  , PND  , TILD ,  xx  ,  xx  ,  xx  ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                            xx  ,  xx  ,  xx  ,   xx  ,                xx  ,  xx  ,  xx  ,  xx
    //                   +------+------+------+------/              \------+------+------+------+
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln_P(PSTR("LAYER"), false);
    oled_write_ln_P(PSTR("-----"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERT"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("ERROR"), false);
    }
      //
    // If you want to change the display of OLED, you need to change here
    // oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
