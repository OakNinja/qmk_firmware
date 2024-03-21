/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#define ENCODER_RESOLUTION 2

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#ifndef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 150
#endif

#define RGB_MATRIX_KEYPRESSES // reacts to keypresses (will slow down matrix scan by a lot)
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_BREATHING

/*
//#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT

//#define ENABLE_RGB_MATRIX_BAND_SAT
//#define ENABLE_RGB_MATRIX_BAND_VAL
//#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#define ENABLE_RGB_MATRIX_CYCLE_ALL
//#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
//#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
//#define ENABLE_RGB_MATRIX_DUAL_BEACON
//#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
//#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#define ENABLE_RGB_MATRIX_RAINDROPS
//#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#define ENABLE_RGB_MATRIX_HUE_BREATHING
//#define ENABLE_RGB_MATRIX_HUE_PENDULUM
//#define ENABLE_RGB_MATRIX_HUE_WAVE
//#define ENABLE_RGB_MATRIX_PIXEL_RAIN
//#define ENABLE_RGB_MATRIX_PIXEL_FLOW
//#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL*/
#ifndef KEYBOARD_splitkb_kyria_rev2
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT // Sets the default mode, if none has been set

#define TAPPING_FORCE_HOLD

#define SPLIT_WPM_ENABLE

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 250

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0



//# ifdef CONWAY_ENABLE
//#define SPLIT_TRANSACTION_IDS_USER CONWAY_SYNC
//# endif
