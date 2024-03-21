/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdio.h>

/**
 * Put this somewhere at the beginning of the file --
 * Make sure you import only one of animations at a time
 * They all have same function exported, so it won't compile if you
 * include more than one at a time. You can also configure some options
 * before including the animation. Not all animations support them, but some do :P.
 */
#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

//#include "demon.c"

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}



enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _GAMING,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define GAMING   MO(_GAMING)
#define FKEYS    MO(_FUNCTION)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define RAISE_ENT LT(_NAV, KC_ENT)
#define SPACE_LWR LT(_NAV, KC_SPC)
#define GUI_SHFT LGUI(KC_LSFT)
#define GUI_C LGUI(KC_C)
#define GUI_V LGUI(KC_V)
#define GUI_X LGUI(KC_X)
#define GUI_Z LGUI(KC_Z)
#define GUI_D LGUI(KC_D)
#define GUI_F LGUI(KC_F)

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)



// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Ö~`  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc| (C)A | (A)S | (G)D | (S)F |   G  |                              |   H  |   J  |   K  |   L  |   Å;:|   Ä'"  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |F-keys|  |Lower |Lower |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  SYM | LAlt/| LGUI |Space/|  |Enter/| Bsp  | NAV |  Sym |      |
 *                        |      |      | Enter|      |Lower |  |RAISE |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_TILD,
     CTL_ESC , HOME_A ,HOME_S ,HOME_D  , HOME_F ,   KC_G ,                                        KC_H,HOME_J ,HOME_K, HOME_L ,KC_SCLN, KC_QUOTE,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC, FKEYS,       NAV , NAV, KC_N,   KC_M ,  KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                           KC_NO,  SYM , GAMING, KC_LGUI,  SPACE_LWR,            RAISE_ENT , KC_BSPC, NAV, SYM, KC_NO
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      | Home |   ↑  | End  |  [   |   ]    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LCTRL| LALT | LGUI | LSFT |      |                              |   =  |  ←   |   ↓  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   -  |  (   |  )   |      |  \   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |DELETE|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______ , _______, _______, _______, _______, _______,                                     _______ , KC_HOME, KC_UP,   KC_END,  KC_LBRC, KC_RBRC,
      _______ , KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                                     KC_EQL  , KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINUS, KC_LPRN, KC_RPRN, _______, KC_BSLS, _______,
                                  _______, _______, _______, _______, _______, _______, KC_DEL , _______, _______, _______
),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  |      |      |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     KC_GRV  , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR , KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
     KC_TILD , _______, _______, _______, _______, _______,                                     KC_CIRC, KC_AMPR , KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_F1  ,  KC_F2 , KC_F3  , KC_F4  , KC_F5  , _______, _______, _______, _______, _______,  KC_F6  ,  KC_F7 , KC_F8 , KC_F9 , KC_F10 ,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: F/Adjust keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      | Reset  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     RGB_M_R, _______, _______, _______,  _______, QK_BOOT,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /*
 * Gaming Layer:
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAMING] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     _______,  KC_7  ,  KC_8  ,  KC_9  , _______, _______,
       _______, _______, _______, GUI_D  , GUI_F  , _______,                                     _______,  KC_4  ,  KC_5  ,  KC_6  , _______, _______,
       _______, GUI_Z  , GUI_X  , GUI_C  , GUI_V  , _______, _______, _______, _______, _______, _______,  KC_1  ,  KC_2  ,  KC_3  , _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______,  KC_0  , _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// called on every keypress
//bool process_record_user(uint16_t keycode, keyrecord_t *record)
//{
//    // Fun, lets make a heat map!
//    return true;
//}


// #ifdef OLED_DRIVER_ENABLE
#if defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)

#define WIDTH 128

char wpm_str[8];

void render_wpm(void) {
    oled_set_cursor(7,6);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}
/**
 * renders a PROGMEM uint16_t array, smaller or equal in size than the OLED
 * x, y: top left position of the image
 * width: width of the image
 */
void render_short_array_pos(const uint16_t* frame, uint8_t x, uint8_t y, uint8_t width)
{
    uint16_t size = pgm_read_word(&(frame[0])) + 1;
    for(uint16_t i=1; i<size; i++)
    {
        uint16_t cur_px = pgm_read_word(&(frame[i]));

        // get pixel state bit
        bool on = (cur_px & (1<<15)) >> 15;
        // remove pixel state bit
        cur_px &= ~(1UL << 15);

        uint8_t x_cur = (cur_px % width) + x;
        uint8_t y_cur = (cur_px / width) + y;
        oled_write_pixel(x_cur, y_cur, on);
    }
}

/**
 * Shortcut to render images of the size of the OLED
 */
void render_short_array(const uint16_t* frame)
{
    render_short_array_pos(frame, 0, 0, WIDTH);
}

// originally by j-inc: https://github.com/qmk/qmk_firmware/blob/master/keyboards/kyria/keymaps/j-inc/keymap.c
// Adapted to modular system and diffs using uint16_t arrays by Dakes (Daniel Ostertag).

// WPM-responsive animation stuff here
#define IDLE_FRAMES 5 // 5
#define IDLE_SPEED 10 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 30 // above this wpm value typing animation to triggere

#define PREP_FRAMES 1

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms 200
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;


// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.

void render_anim(void)
{
    // bongocat frames
    // saves the pixel index in bits 1-13 and pixel on, off in bit 16. 1: on 0: off (+2^15)
    // first element is the size of the array , without the size itself
    static const uint16_t base[] PROGMEM = {223, 32968, 32969, 32970, 33095, 33099, 33222, 33228, 33346, 33347, 33348, 33349, 33356, 33470, 33471, 33472, 33473, 33484, 33596, 33597, 33613, 33723, 33742, 33789, 33790, 33791, 33844, 33845, 33850, 33871, 33872, 33913, 33914, 33915, 33916, 33971, 33974, 33975, 33976, 33977, 34001, 34036, 34037, 34038, 34039, 34040, 34098, 34130, 34160, 34161, 34162, 34163, 34226, 34259, 34283, 34284, 34285, 34286, 34287, 34354, 34379, 34380, 34388, 34407, 34408, 34409, 34410, 34483, 34507, 34508, 34517, 34530, 34531, 34532, 34533, 34534, 34611, 34638, 34639, 34640, 34641, 34646, 34654, 34655, 34656, 34657, 34740, 34751, 34752, 34762, 34766, 34767, 34768, 34769, 34775, 34779, 34780, 34781, 34868, 34879, 34880, 34884, 34887, 34888, 34889, 34890, 34903, 34904, 34905, 34906, 34996, 35013, 35014, 35032, 35123, 35132, 35133, 35134, 35135, 35150, 35151, 35160, 35250, 35260, 35261, 35262, 35263, 35273, 35274, 35275, 35276, 35277, 35280, 35281, 35288, 35378, 35397, 35398, 35399, 35400, 35410, 35411, 35412, 35413, 35414, 35415, 35506, 35522, 35523, 35524, 35633, 35649, 35761, 35778, 35889, 35892, 35893, 35894, 35895, 35896, 35897, 35906, 36016, 36017, 36018, 36019, 36026, 36027, 36034, 36142, 36143, 36156, 36157, 36162, 36266, 36267, 36268, 36269, 36286, 36287, 36288, 36289, 36390, 36391, 36392, 36393, 36514, 36515, 36516, 36517, 36638, 36639, 36640, 36641, 36762, 36763, 36764, 36765, 36886, 36887, 36888, 36889, 37010, 37011, 37012, 37013, 37134, 37135, 37136, 37137, 37258, 37259, 37260, 37261, 37382, 37383, 37384, 37385, 37506, 37507, 37508, 37509, 37632, 37633};

    // diffs rendered after base frame, turns on/off certain pixels
    // unfortunately C Arrays can't have a variable second dimension
    static const uint16_t idle_diff_0[] PROGMEM = {0};
    static const uint16_t idle_diff_2[] PROGMEM = {22, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33970, 1203, 1206, 1207};
    static const uint16_t idle_diff_3[] PROGMEM = {104, 200, 327, 33096, 454, 33223, 578, 579, 580, 581, 33350, 702, 703, 704, 705, 33474, 33475, 33476, 33477, 716, 33485, 828, 829, 33598, 33599, 33600, 33601, 955, 33724, 33725, 33741, 974, 1082, 33851, 33870, 1103, 1104, 1208, 1209, 33978, 33999, 34000, 1233, 34104, 34105, 34129, 1362, 34258, 1491, 1611, 1612, 34387, 1620, 34482, 1715, 34516, 1749, 34635, 34636, 1870, 1871, 1872, 1873, 34645, 1878, 34739, 1972, 1983, 1984, 1994, 34774, 2007, 2116, 2119, 2120, 2121, 34894, 34895, 34896, 34897, 35007, 35008, 35012, 2245, 2246, 35015, 35016, 35017, 35018, 2355, 35124, 2364, 2365, 2366, 2367, 35141, 35142, 2482, 35251, 35388, 35389, 35390, 35391, 2865, 35634};
    static const uint16_t idle_diff_4[] PROGMEM = {20, 200, 201, 202, 327, 33096, 33097, 33098, 331, 454, 33223, 33227, 460, 33350, 1076, 1077, 1203, 33972, 33973, 1330, 34099};
    static const uint16_t *idle_diff[IDLE_FRAMES] = {
            idle_diff_0,
            idle_diff_0, // first two frames are identical
            idle_diff_2,
            idle_diff_3,
            idle_diff_4
    };

    static const uint16_t prep_diff_0[] PROGMEM = {107, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33875, 33876, 33877, 33878, 33970, 1203, 1206, 1207, 34002, 34007, 34133, 34136, 34257, 34263, 34264, 34385, 34389, 34392, 34512, 34516, 34520, 1870, 1871, 1873, 1878, 34648, 34746, 34747, 34748, 1998, 1999, 2001, 34873, 34875, 34877, 35000, 35005, 35027, 35028, 35029, 35030, 2264, 35128, 35129, 2365, 2367, 35152, 35153, 35154, 2392, 35255, 35258, 35259, 2492, 2493, 2495, 2512, 2513, 2520, 35383, 35386, 35387, 35390, 2642, 2643, 2644, 2645, 2646, 2647, 35518, 35646, 35647, 35648, 35770, 35771, 35772, 35773, 3010, 3138, 3258, 3259, 3266, 3388, 3389, 3394, 3518, 3519, 3520, 3521};
    static const uint16_t *prep_diff[PREP_FRAMES] = {
            prep_diff_0
    };

    static const uint16_t tap_diff_0[] PROGMEM = {187, 32841, 32842, 201, 202, 32971, 331, 33100, 33238, 33239, 33240, 33241, 588, 33357, 33366, 33367, 33368, 33369, 716, 33485, 33494, 33495, 33496, 33497, 33622, 33623, 33624, 33625, 33716, 33717, 33750, 33751, 33752, 33753, 33759, 33760, 33843, 1076, 1077, 33846, 33847, 33878, 33879, 33880, 33881, 33886, 33887, 33888, 33889, 33970, 1203, 1206, 1207, 34006, 34007, 34008, 34013, 34014, 34015, 34016, 34017, 34135, 34136, 34140, 34141, 34142, 34143, 34144, 34145, 34146, 34264, 34267, 34268, 34269, 34270, 34271, 34272, 34273, 34274, 34395, 34396, 34397, 34398, 34399, 34400, 34523, 34524, 1870, 1871, 1872, 1873, 34746, 34747, 34748, 1998, 1999, 2000, 2001, 34873, 34875, 34877, 2135, 35000, 35005, 35128, 35129, 2365, 2367, 35162, 35163, 35164, 35165, 35166, 35167, 35168, 35169, 35170, 35255, 35258, 35259, 2492, 2493, 2495, 35290, 35291, 35292, 35293, 35294, 35295, 35296, 35297, 35298, 35383, 35386, 35387, 35390, 35418, 35419, 35420, 35421, 35422, 35423, 35424, 35425, 35518, 35546, 35547, 35548, 35549, 35550, 35551, 35552, 35553, 35646, 35647, 35648, 35675, 35676, 35677, 35678, 35679, 35680, 35770, 35771, 35772, 35773, 3010, 35804, 35805, 35806, 35807, 35808, 3138, 35933, 35934, 35935, 3258, 3259, 3266, 36062, 36063, 3388, 3389, 3394, 3518, 3519, 3520, 3521};
    static const uint16_t tap_diff_1[] PROGMEM = {187, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33875, 33876, 33877, 33878, 33970, 1203, 1206, 1207, 34002, 34007, 34133, 34136, 34257, 34263, 34264, 34385, 34389, 34392, 34512, 34516, 34520, 1870, 1871, 1873, 1878, 34648, 1998, 1999, 2001, 35027, 35028, 35029, 35030, 2264, 2364, 2365, 2366, 2367, 35152, 35153, 35154, 2392, 2492, 2493, 2494, 2495, 2512, 2513, 2520, 2642, 2643, 2644, 2645, 2646, 2647, 36274, 36275, 36276, 36277, 36278, 36279, 36280, 36402, 36403, 36404, 36405, 36406, 36407, 36408, 36409, 36530, 36531, 36532, 36533, 36534, 36535, 36536, 36537, 36658, 36659, 36660, 36661, 36662, 36663, 36800, 36801, 36802, 36803, 36922, 36923, 36924, 36928, 36929, 36930, 36931, 36932, 37049, 37050, 37051, 37052, 37056, 37057, 37058, 37059, 37060, 37061, 37176, 37177, 37178, 37179, 37180, 37184, 37185, 37186, 37187, 37188, 37189, 37190, 37303, 37304, 37305, 37306, 37307, 37312, 37313, 37314, 37315, 37316, 37317, 37318, 37319, 37430, 37431, 37432, 37433, 37434, 37435, 37440, 37441, 37442, 37443, 37444, 37445, 37446, 37447, 37558, 37559, 37560, 37561, 37562, 37563, 37568, 37569, 37570, 37571, 37572, 37573, 37687, 37688, 37689, 37690, 37696, 37697, 37698, 37699, 37817, 37818, 37824, 37825};
    static const uint16_t *tap_diff[TAP_FRAMES] = {
            tap_diff_0,
            tap_diff_1
    };

    //assumes 1 frame prep stage
    void animation_phase(void)
    {
        oled_clear();
        if (get_current_wpm() <= IDLE_SPEED)
        {
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            // first render base frame
            render_short_array(base);
            // only add or remove changed pixels
            render_short_array(idle_diff[ current_idle_frame ]);
        }
        if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED)
        {
            render_short_array(base);
            render_short_array(prep_diff[0]);
        }
        if (get_current_wpm() >= TAP_SPEED)
        {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            render_short_array(base);
            render_short_array(tap_diff[ current_tap_frame ]);
        }
    }

    if(get_current_wpm() != 0)
    {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
        {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else
    {
        if(false && timer_elapsed32(anim_sleep) > OLED_TIMEOUT)
        {
            oled_off();
        } else
        {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
            {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

#endif

#if defined(OLED_ENABLE)

// OLED width
#define WIDTH 128

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
	return OLED_ROTATION_180;
}

static void render_current_layer(void)
{
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("F Keys / Whoami?"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }

    //Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("       "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("       "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRL") : PSTR("       "), false);
}

/**
 ** return: if true, start scrolling, to reduce burn in
 ** return: if false, content changed, do not scroll
 */
static bool render_status(void)
{
    static uint8_t scroll_timer = 0;

    render_current_layer();
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
    //oled_write_P() is_keyboard_master()

    if (scroll_timer < 255)
        scroll_timer++;

    if (scroll_timer < 255)
        return false;
    else
        return true;
}

bool oled_task_user(void)
{
    if (is_keyboard_master())
    {
        // Will scroll OLED, if "home" screen was displayed for 255 refreshes
        // TODO: random vertical offset
        oled_set_cursor(0,4);
        bool render_stat_ret = render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        if (render_stat_ret)
            oled_scroll_left();
        else
            oled_scroll_off();
    } else
    {
        oled_on();
        render_anim();
        render_wpm();
    }
    return false;
}


#endif // defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)
