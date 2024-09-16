#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ BS│
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ESC│
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │TAB│
     * ├───┼───┼───┼───┤
     * │FN │ 0 │ . │RET│
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_ortho_4x4(
        KC_P7,    KC_P8,  KC_P9,    KC_BSPC,
        KC_P4,    KC_P5,  KC_P6,    KC_ESC,
        KC_P1,    KC_P2,  KC_P3,    KC_TAB,
        TT(_FN1), KC_P0,  KC_PDOT,  KC_ENTER
    ),

    [_FN1] = LAYOUT_ortho_4x4(
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
    ),

    [_FN2] = LAYOUT_ortho_4x4(
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
    ),

    [_FN3] = LAYOUT_ortho_4x4(
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
    )
};

#ifdef RGB_MATRIX_ENABLE
#define XX NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { 0, 4, 8, 12 },
        { 1, 5, 9, 13 },
        { 2, 6, 10, 14  },
        { 3, 7, 11, 15 }
    }, {
        // LED Index to Physical Position
        {0,0},  {0,8},  {0,16},  {0,24},  {0,32},  {0,40},  {0,48},  {0,56},  //{0,64},
        {244,0},{244,8},{244,16},{244,24},{244,32},{244,40},{244,48},{244,56},//{244,64},
    }, {
        // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 
    }
};
#endif

/*
 * ROTARY ENCODER
 */

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
//     [_FN1] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
//     [_FN2] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
//     [_FN3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)},
// };
// #endif