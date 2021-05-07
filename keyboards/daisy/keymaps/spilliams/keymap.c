#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BL,
    _NL,
    _SL,
    _FL,
    _CL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    // base layer
    [_BL] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MO(_NL),
        KC_LCTL, KC_LALT, LT(_NL, KC_LGUI), KC_BSPC,           KC_SPC,             MO(_FL), MO(_CL), MO(_SL)
    ),
    
    // number layer
    [_NL] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_GRV,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
        _______, _______, KC_TRNS,        _______,               _______,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // symbol layer
    [_SL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_TRNS,
        _______, _______, KC_TRNS,        KC_DEL,                _______,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // function layer
    [_FL] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_GRV,  _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
        _______, _______, KC_TRNS,        KC_DEL,                _______,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // control layer
    [_CL] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MPLY, _______, _______, KC_SLEP,
        _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, BL_STEP, KC_TRNS,
        _______, _______, KC_TRNS,        _______,               _______,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // [] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
    //     _______, _______, KC_TRNS,        _______,               _______,       KC_TRNS, KC_TRNS, KC_TRNS
    // )
};
