#include QMK_KEYBOARD_H

enum layer_names {
  BASE,
  RAISE,
  MORE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x7_4(
    KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_HOME  ,      KC_PGUP, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_END   ,      KC_PGDN, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , MO(RAISE),    MO(RAISE), KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                               KC_LCTL, KC_LALT, KC_BSPC, KC_DEL   ,       KC_ENT, KC_SPC , KC_LGUI, KC_RCTL
  ),
  
  [RAISE] = LAYOUT_split_3x7_4(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_EQL   ,      KC_MINS, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
    KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_LBRC  ,      KC_RBRC, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_LBRC, KC_RBRC,
    KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , MO(MORE) ,     MO(MORE), KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  ,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  
  [MORE] = LAYOUT_split_3x7_4(
    KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F12   ,       KC_F11, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
    KC_SLEP, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO    ,        KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO  , KC_NO  ,
    KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , MO(MORE) ,     MO(MORE), KC_NO  , KC_NO  , KC_MUTE, KC_MPLY, KC_NO  , KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  ,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};
