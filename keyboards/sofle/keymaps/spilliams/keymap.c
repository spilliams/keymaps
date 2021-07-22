#include QMK_KEYBOARD_H

enum sofle_layers {
    BASE,
    SUPE,
    HYPE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * Encoders do Home/End and PgUp/PgDn
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  []  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Play  |    | Mute  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCtl | LAlt | SUPE | Bspc | /  Del  /       \ Ret  \  | Spc  | SUPE | GUI  | RCtl |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[BASE] = LAYOUT( \
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
    KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS, \
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,   KC_MUTE, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                KC_LCTL,  KC_LALT,  MO(SUPE), KC_BSPC,  KC_DEL,    KC_ENT,   KC_SPC, MO(SUPE), KC_LGUI,  KC_RCTL \
),
/*
 * Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ---- |      |      |      |      |  =   |                    |   -  |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---- |      |      |  {   |  }   |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---- |      |      |  (   |  )   |      |-------.    ,-------|  <-  |  ^^  |  vv  |  ->  |      |      |
 * |------+------+------+------+------+------| ----  |    | ----  |------+------+------+------+------+------|
 * | ---- |      |      |  [   |  ]   |      |-------|    |-------|      |      |      |      |      | ---- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | ____ | ____ | HYPE | ____ | / ____  /       \ ____ \  | ____ | HYPE | ____ | ____ |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[SUPE] = LAYOUT( \
    KC_TRNS, KC_NO,  KC_NO,  KC_NO,   KC_NO,    KC_EQL,                   KC_MINS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_EQL, \
    KC_TRNS, KC_NO,  KC_NO,  KC_LCBR, KC_RCBR,  KC_NO,                      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_TRNS, KC_NO,  KC_NO,  KC_LPRN, KC_RPRN,  KC_NO,                      KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT, KC_NO,  KC_NO, \
    KC_TRNS, KC_NO,  KC_NO,  KC_LBRC, KC_RBRC,  KC_NO, KC_TRNS,   KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS, \
               KC_TRNS,  KC_TRNS,  MO(HYPE), KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS, MO(HYPE), KC_TRNS, KC_TRNS \
),
/* Hyper
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | SLEEP|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---- |      |      |      |      |      |                    |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ---- |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | ---- |      |      |      |      |      |-------|    |-------|      |      |      |      |      | ---- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | ____ | ____ | ____ | ____ | / ____  /       \ ____ \  | ____ | ____ | ____ | ____ |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[HYPE] = LAYOUT( \
    KC_SLEP,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                       KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,\
    KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_F12, \
    KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
    KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS, \
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS\
)
};

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void)
{
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    if (is_keyboard_master())
    {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void)
{
    render_logo();
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise)
{
    // TODO: can the encoders do different things on different layers?
    if (index == 0)
    {
        if (clockwise)
        {
            tap_code(KC_END);
        }
        else
        {
            tap_code(KC_HOME);
        }
    }
    else if (index == 1)
    {
        if (clockwise)
        {
            tap_code(KC_PGDOWN);
        }
        else
        {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
