/*
Copyright 2021 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "lib/keyball/keyball.h"

//////////////////////////////////////////////////////////////////////////////

// clang-format off
matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b01110111,
    0b01110111,
    0b01110111,
    0b11110111,
    0b11110111,
    0b01110111,
    0b01110111,
    0b01110111,
    0b11110111,
    0b11110111,
};
// clang-format on

void keyball_on_adjust_layout(keyball_adjust_t v) {
#ifdef RGBLIGHT_ENABLE
    // adjust RGBLIGHT's clipping and effect ranges
    uint8_t lednum_this = keyball.this_have_ball ? 34 : 37;
    uint8_t lednum_that = !keyball.that_enable ? 0 : keyball.that_have_ball ? 34 : 37;
    rgblight_set_clipping_range(is_keyboard_left() ? 0 : lednum_that, lednum_this);
    rgblight_set_effect_range(0, lednum_this + lednum_that);
#endif
}

// key combo
#ifdef COMBO_ENABLE
    enum combos{
        UI_UP,
        MC_DOWN,
        JK_LEFT,
        KL_RIGHT,
    };

    const uint16_t PROGMEM my_ui[] = {KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM my_mco[] = {KC_M, KC_COMM, COMBO_END};
    const uint16_t PROGMEM my_jk[] = {KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM my_kl[] = {KC_K, KC_L, COMBO_END};

    combo_t key_combox[] = {
        [UI_UP] = COMBO(my_ui, KC_UP),
        [MC_DOWN] = COMBO(my_mco, KC_DOWN),
        [JK_LEFT] = COMBO(my_jk, KC_LEFT),
        [KL_RIGHT] = COMBO(my_kl, KC_RGHT),
    };
#endif
