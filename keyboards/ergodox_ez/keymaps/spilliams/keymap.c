#include QMK_KEYBOARD_H
#include "version.h"
#include "action_layer.h"
// #include "keymap_steno.h"

enum layers {
    // STEN, // gotta type fast
    QWER, // default layer
    // APPL, // swaps the OS and Alt
    GAME, // for the lulz
    SYMB, // all the squiggly ones
    MOUS, // for the mouse
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Steno Layer (place below QWER to enable the LM for ctrl, alt, etc)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   Esc  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |   `~   |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |   Tab  |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |  Shift |   S  |   K  |   W  |   R  |   *  | QWER |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | Ctrl |(SYMB)|(MOUS)|  Gui |  Alt |                                       | Left | Down |  Up  | Right|      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |Mouse1|Mouse2|       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |   A  |   O  |------|       |------|   E  |   U  |
    *                                 |      |      | Bkspc|       |  Del |      |      |
    *                                 `--------------------'       `--------------------'
    */
    // [STEN] = LAYOUT_ergodox_pretty(
    // KC_ESC,             _______,  _______,  _______,            _______,            _______, _______,    _______,  _______, _______, _______, _______, _______,  _______,
    // KC_GRV,             STN_N1,   STN_N2,   STN_N3,             STN_N4,             STN_N5,  _______,    _______,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,   STN_NB,
    // KC_TAB,             STN_S1,   STN_TL,   STN_PL,             STN_HL,             STN_ST1,                       STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,   STN_DR,
    // LM(QWER, MOD_LSFT), STN_S2,   STN_KL,   STN_WL,             STN_RL,             STN_ST1, TG(QWER),   _______, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,   STN_ZR,
    // LM(QWER, MOD_LCTL), MO(SYMB), MO(MOUS),LM(QWER, MOD_LGUI), LM(QWER, MOD_LALT),                                         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
    //                                                                                 KC_BTN1, KC_BTN2,    _______,  _______,
    //                                                                                          _______,    _______,
    //                                                             STN_A,              STN_O,   KC_BSPC,    KC_DEL,   STN_E,   STN_U
    // ),
    /* QWERTY Layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * | Esc    |   1  |   2  |   3  |   4  |   5  |  =   |           |   -  |   6  |   7  |   8  |   9  |   0  |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Grave  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
    * |--------+------+------+------+------+------| GAME |           |      |------+------+------+------+------+--------|
    * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | LCtrl|(SYMB)|(MOUS)| LGui | LAlt |                                       | Left | Down |  Up  | Right| RCtrl|
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |Mouse1|Mouse2|       |  F5  |  F9  |
    *                                 ,------|------|------|       |------+--------+------.
    *                                 |Back- |      | Home |       | PgUp |        |      |
    *                                 | space| Del  |------|       |------| Enter  |Space |
    *                                 |      |      | End  |       | PgDn |        |      |
    *                                 `--------------------'       `----------------------'
    */
    [QWER] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_1,     KC_2,  KC_3,    KC_4,    KC_5,    KC_EQL,    KC_MINS,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_ESC,
    KC_GRV,  KC_Q,     KC_W,  KC_E,    KC_R,    KC_T,    TG(GAME),  KC_NO,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_BSLS,
    KC_TAB,  KC_A,     KC_S,  KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,     KC_X,  KC_C,    KC_V,    KC_B,    KC_NO,     KC_NO,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
    KC_LCTL,MO(SYMB),MO(MOUS),KC_LGUI, KC_LALT,                                        KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_RCTL,
                                                 KC_BTN1, KC_BTN2,  KC_F5,    KC_F9,
                                                          KC_HOME,  KC_PGUP,
                                        KC_BSPC, KC_DEL,   KC_END,  KC_PGDN, KC_ENT, KC_SPC
    ),
    /* Apple Layer (blank keys are transparent to lower layers)
    *
    * ,---------------------------------------------------.           ,--------------------------------------------------.
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           | EXIT |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |       |      |      | LAlt | LGui |                                       |      |      |      |      |      |
    *   `-----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    // [APPL] = LAYOUT_ergodox_pretty(
    // _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______, _______,     KC_TRNS, _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, KC_LALT, KC_LGUI,                                         _______, _______, _______, _______, _______,
    //                                              _______, _______,     _______, _______,
    //                                                       _______,     _______,
    //                                     _______, _______, _______,     _______, _______, _______
    // ),
    /* Gaming Layer (blank keys are transparent to lower layers)
    *
    * ,---------------------------------------------------.           ,--------------------------------------------------.
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------| EXIT |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |       |      |      | LAlt | Space|                                       |      |      |      |      |      |
    *   `-----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |  I   |  L   |       |  F5  |  F9  |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |  N   |       | LGui |      |      |
    *                                 | Space| Down |------|       |------|      |      |
    *                                 |      |      |  M   |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    [GAME] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_TRNS,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LALT, KC_SPC,                                          _______, _______, _______, _______, _______,
                                                 KC_I,    KC_L,        KC_TRNS, KC_TRNS,
                                                          KC_N,        KC_LGUI,
                                        KC_SPC, KC_DOWN,  KC_M,        _______, _______, _______
    ),
    /* Symbol Layer
    *
    * ,---------------------------------------------------.          ,--------------------------------------------------.
    * |  Sleep  |  F1  |  F2  |  F3  |  F4  |  F5  |      |          |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
    * |---------+------+------+------+------+------+------|          |------+------+------+------+------+------+--------|
    * | Version |   !  |   @  |   {  |   }  |   |  |      |          |      |      |      |      |      |      |   F12  |
    * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+--------|
    * |  Reset  |   #  |   $  |   (  |   )  |   `  |------|          |------|      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+--------|
    * |   Wake  |   %  |   ^  |   [  |   ]  |   ~  |      |          |      |      |      | Mute | Play |      |        |
    * `---------+------+------+------+------+-------------'          `-------------+------+------+------+------+--------'
    *   |       | Exit |      |      |      |                                      | Prev | VolDn| VolUp| Next |      |
    *   `-----------------------------------'                                      `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      | www  | www  |
    *                                 |      |      |------|       |------| Back |  Fwd |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    [SYMB] = LAYOUT_ergodox_pretty(
    KC_SLEP, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    VRSN,    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,     _______, _______, _______, _______, _______, _______, KC_F12,
    RESET,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        _______, _______, _______, _______, _______, _______,
    KC_WAKE, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,     _______, _______, _______, KC_MUTE, KC_MPLY, _______, _______,
    _______, KC_TRNS, _______, _______, _______,                                         KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
                                                 _______, _______,     _______, _______,
                                                          _______,     _______,
                                        _______, _______, _______,     _______, KC_WBAK, KC_WFWD
    ),
    /* Mouse Layer (blank keys are transparent to lower layers)
    *
    * ,---------------------------------------------------.           ,--------------------------------------------------.
    * |MouseAcc0|MAccl1|MAccl2|      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |       |      | EXIT |      |      |                                       |MouseL|MouseD|MouseU|MouseR|      |
    *   `-----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |Mouse3|Mouse4|       |Mouse5|Mouse6|
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |MsWh U|       |MsWh L|      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |Mouse1|Mouse2|MsWh D|       |MsWh R|Mouse1|Mouse2|
    *                                 `--------------------'       `--------------------'
    */
    [MOUS] = LAYOUT_ergodox_pretty(
    KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_TRNS, _______, _______,                                         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
                                                 KC_BTN3, KC_BTN4,     KC_BTN5, KC_BTN6,
                                                          KC_WH_U,     KC_WH_L,
                                        KC_BTN1, KC_BTN2, KC_WH_D,     KC_WH_R, KC_BTN1, KC_BTN2
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    rgb_matrix_enable();

    // NOTE: "GeminiPR" is a stenography protocol that I've chosen to use when
    // communicating with Plover. The other option was "TX Bolt".
    // Although QMK says TX Bolt is the "default" protocol, it is an older
    // protocol than GeminiPR.
    // More information in the QMK docs:
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_stenography.md#plover-with-steno-protocol
    // steno_set_mode(STENO_MODE_GEMINI);
};

/* Indices of the LED arrays
* ,---------------------------------------------------.           ,--------------------------------------------------.
* |         |  28  |  27  |  26  |  25  |  24  |      |           |      |  0   |   1  |   2  |   3  |   4  |        |
* |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
* |         |  33  |  32  |  31  |  30  |  29  |      |           |      |  5   |   6  |   7  |   8  |   9  |        |
* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |         |  38  |  37  |  36  |  35  |  34  |------|           |------|  10  |  11  |  12  |  13  |  14  |        |
* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |         |  43  |  42  |  41  |  40  |  39  |      |           |      |  15  |  16  |  17  |  18  |  19  |        |
* `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |       |  47  |  46  |  45  |  44  |                                       |  20  |  21  |  22  |  23  |      |
*   `-----------------------------------'                                       `----------------------------------'
*/
// 255=red
// 201=purple
// 78=green
// 145=blue
// 26=yellow
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // [STEN] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },
    [QWER] = { {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255} },
    // [APPL] = { {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255} },
    [GAME] = { {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255} },
    [SYMB] = { {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {26,255,255}, {26,255,255}, {0,0,0}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255} },
    [MOUS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
    }
}

void rgb_matrix_indicators_user(void) {
    // if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
    if (keyboard_config.disable_layer_led) { return; }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
            rgb_matrix_set_color_all(0, 0, 0);
        break;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    return state;
};
