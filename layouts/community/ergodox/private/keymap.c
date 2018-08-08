#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define FN1  1 // media layer

#define CAPS_SFT MT(MOD_LSFT, KC_CAPS)
#define QUOT_SFT MT(MOD_RSFT, KC_QUOT)
#define DOWN_ALT MT(MOD_RALT, KC_DOWN)
#define EQL_CTL MT(MOD_RCTL, KC_EQL)
#define ESC_FN LT(FN1, KC_ESC)
#define GRV_FN LT(FN1, KC_GRV)
#define RBRC_FN LT(FN1, KC_RBRC)
#define PGDN_GUI MT(MOD_LGUI, KC_PGDN)
#define DOWN_GUI MT(MOD_RGUI, KC_DOWN)
#define HOME_GUI MT(MOD_LGUI, KC_HOME)
#define RGHT_GUI MT(MOD_RGUI, KC_RIGHT)
#define LEFT_ALT MT(MOD_LALT, KC_LEFT)
#define LBRC_CTL MT(MOD_LCTL, KC_LBRC)
#define MINS_CTL MT(MOD_LCTL, KC_MINS)
#define RGHT_SFT MT(MOD_LSFT, KC_RGHT)
#define RBRC_CTL MT(MOD_RCTL, KC_RBRC)
#define UP_SFT MT(MOD_RSFT, KC_UP)
#define DEL_ALT MT(MOD_LALT, KC_DEL)
#define ENT_ALT MT(MOD_RALT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Fn   |   1  |   2  |   3  |   4  |   5  | `/FN |           |Esc/FN|   6  |   7  |   8  |   9  |   0  |   Fn   |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | LALT |           | RALT |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Caps/Sft|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | '/Shift|
 * |--------+------+------+------+------+------| LCTL |           | RCTL |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  [   |           |  ]   |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | SysRq|  Ins |   [  | -/Ctl|                                       | =/Ctl| ]/Fn | Del  | Pause| RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Home/G|  End |       | Left |Rght/G|
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      | PgUp |       |  Up  |      |      |
 *                                 |BSpace| Del/ |------|       |------|Enter/| Space|
 *                                 |      | LAlt |PD/Gui|       |Dn/Gui| RAlt |      |
 *                                 `--------------------'       `--------------------'
 */

    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // Left hand
        TT(FN1),  KC_1,      KC_2,      KC_3,     KC_4,     KC_5,    GRV_FN,
        KC_TAB,   KC_Q,      KC_W,      KC_E,     KC_R,     KC_T,    KC_LALT,
        CAPS_SFT, KC_A,      KC_S,      KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,    LBRC_CTL,
        KC_LCTL,  KC_SYSREQ, KC_INS,    KC_LBRC,  MINS_CTL,
        HOME_GUI, KC_END,
        KC_PGUP,
        KC_BSPC,  DEL_ALT,    PGDN_GUI,

        // Right hand
        ESC_FN,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    TT(FN1),
        KC_RALT,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_BSLS,
                  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN, QUOT_SFT,
        RBRC_CTL, KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,
        EQL_CTL,  RBRC_FN,  KC_DEL,   KC_PAUSE, KC_RCTL,
        KC_LEFT,  RGHT_GUI,
        KC_UP,
        DOWN_GUI, ENT_ALT, KC_SPC),

/* Keymap 1: Fn Keys, media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |   F11  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |  Up  |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LClk | MClk | RClk |      |      |           |      |      |      | Left | Down | Rght |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |Teensy|       | Prev | Next |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       | VolUp|      |      |
 *                                 |      |      |------|       |------| Mute | Play |
 *                                 |      |      |      |       | VolDn|      |      |
 *                                 `--------------------'       `--------------------'
 */

// FN1 Layer
    [FN1] = LAYOUT_ergodox(
        // Left hand
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RESET,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Right hand
        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),
};

const uint16_t PROGMEM fn_actions[] = {
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
        ergodox_right_led_1_on();
        break;
    default:
        // none
        ergodox_right_led_1_off();
        break;
    }

};

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}
