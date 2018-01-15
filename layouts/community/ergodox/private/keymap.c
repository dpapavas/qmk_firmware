#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define FN1  1 // media layer

#define CAPS_GUI MT(MOD_LGUI, KC_CAPS)
#define UP_SFT MT(MOD_RSFT, KC_UP)
#define RGHT_SFT MT(MOD_LSFT, KC_RGHT)
#define DOWN_ALT MT(MOD_RALT, KC_DOWN)
#define LEFT_ALT MT(MOD_LALT, KC_LEFT)
#define LPRN_CTL MT(MOD_LCTL, LSFT(KC_9))
#define RPRN_CTL MT(MOD_RCTL, RSFT(KC_0))
#define LBRC_ALT MT(MOD_LALT, KC_LBRC)
#define RBRC_ALT MT(MOD_RALT, KC_RBRC)
#define MINS_ALT MT(MOD_LALT, KC_MINS)
#define EQL_ALT MT(MOD_RALT, KC_EQL)
#define LBRC_GUI MT(MOD_RGUI, KC_LBRC)
#define RBRC_GUI MT(MOD_LGUI, KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Home |           |  End |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | LALT |           | RALT |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * |Caps/Gui|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| LCTL |           | RCTL |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  (   |           |  )   |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  Fn  | SysRq|[/LGui| -/Alt|                                       | =/Alt|]/RGui| Pause|  Fn  | RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ins  | Del  |       | Left | Right|
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      | PgUp |       |  Up  |      |      |
 *                                 |Enter | Del  |------|       |------|BSpace| Space|
 *                                 |      |      | PgDn |       | Down |      |      |
 *                                 `--------------------'       `--------------------'
 */

    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // Left hand
        KC_GRV,   KC_1,    KC_2,      KC_3,     KC_4,     KC_5,    KC_HOME,
        KC_TAB,   KC_Q,    KC_W,      KC_E,     KC_R,     KC_T,    LBRC_ALT,
        CAPS_GUI, KC_A,    KC_S,      KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,    KC_X,      KC_C,     KC_V,     KC_B,    LPRN_CTL,
        KC_LCTL,  TT(FN1), KC_SYSREQ, LBRC_GUI, MINS_ALT,
        KC_INS,   KC_DEL,
        KC_PGUP,
        KC_ENT,   KC_DEL,  KC_PGDN,

        // Right hand
        KC_END,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_ESC,
        RBRC_ALT, KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_BSLS,
                  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN, KC_QUOT,
        RPRN_CTL, KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,
        EQL_ALT,  RBRC_GUI, KC_PAUSE, TT(FN1),  KC_RCTL,
        KC_LEFT,  KC_RIGHT,
        KC_UP,
        KC_DOWN,  KC_BSPC, KC_SPC),
/* Keymap 1: Fn Keys, media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |  Up  |      |      |   F11  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down | Rght |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LClk | MClk | RClk |      |      |           |      |      |      |      |      |      |        |
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
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RESET,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Right hand
        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_F11,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    switch (layer) {
        // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
        ergodox_right_led_1_on();
        break;
    default:
        // none
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
