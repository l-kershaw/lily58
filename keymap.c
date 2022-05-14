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
#define KC_LOWR MO(_LOWER)          // Lower layer
#define KC_RAIS MO(_RAISE)          // Raise layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
         ESC  ,  1   ,  2   ,  3   ,  4   ,  5   ,                         6   ,  7   ,  8   ,  9   ,  0   , DEL  ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
         TAB  ,  Q   ,  W   ,  E   ,  R   ,  T   ,                         Y   ,  U   ,  I   ,  O   ,  P   , BSPC ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
         LSFT ,  A   ,  S   ,  D   ,  F   ,  G   ,                         H   ,  J   ,  K   ,  L   , SCLN , EQL  ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
         LCTL ,  Z   ,  X   ,  C   ,  V   ,  B   , LBRC ,          RBRC ,  N   ,  M   , COMM , DOT  , SLSH , MINS ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                           LGUI , LCMD , LOWR ,  SPC  ,              ENT   , RAIS , RALT , RGUI
    //                   +------+------+------+------/              \------+------+------+------+
),

[_LOWER] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,                             ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,                             ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,                             ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,      ,               ,      ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                                ,      ,      ,       ,                    ,      ,      ,     
    //                   +------+------+------+------/              \------+------+------+------+
),

[_RAISE] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,                             ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              , WH_L , WH_D , WH_U , WH_R ,      ,                        HOME , PGDN , PGUP , END  ,  xx  , MUTE ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              , MS_L , MS_D , MS_U , MS_R ,      ,                        LEFT , DOWN ,  UP  , RGHT ,  xx  , VOLU  ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
              , ACL0 , ACL1 , ACL2 ,      , BTN2 , BTN3 ,               ,      ,      , MPRV , MPLY , MNXT , VOLD ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                                ,      ,      , BTN1  ,                    ,      ,      ,     
    //                   +------+------+------+------/              \------+------+------+------+
),

[_ADJUST] = LAYOUT_KC(
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,                             ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,                             ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+                      +------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,                             ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+------+        +------+------+------+------+------+------+------+
              ,      ,      ,      ,      ,      ,      ,               ,      ,      ,      ,      ,      ,      ,
    // +------+------+------+------+------+------+------/        \------+------+------+------+------+------+------+
                                ,      ,      ,       ,                    ,      ,      ,     
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
  return rotation;
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
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
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
