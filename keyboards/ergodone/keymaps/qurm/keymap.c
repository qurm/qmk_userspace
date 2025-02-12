#include QMK_KEYBOARD_H
#include "version.h"

#define BASE   0 // default layer
#define SYMB   1 // symbols layer
#define MDIA   2 // media layer
#define SPEC   3 // special layer
#define RBASE  4 // reverse default layer

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    LSymb,  // left symbol-shift key
    LMdia,  // left media-shift key
    LSpec,  // left special-shift key
    RSymb,  // right symbol-shift key
    RMdia,  // right media-shift key
    RSpec,  // right special-shift key

    NotEq,  // != macro
    GrtEq,  // >= macro
    LesEq,  // <= macro
    DeRef,  // -> macro

    MUL,    // mouse up left
    MUR,    // mouse up right
    MDL,    // mouse down left
    MDR    // mouse down right

};


/* Based on the:
 * The Ordinary Layout for the Ergodox EZ keyboard, v5
 *
 * Modifications from the default Ergodox EZ layout
 * by Nicholas Keene ergodoxez@nicholaskeene.com
 *
 * No rights reserved. This software is in the public domain.
 * Credit me if you are friendly but if you're a jerk don't bother.
 * If you use or modify this layout I would love to hear from you.
 *
 * Details: readme.md
 *          https://github.com/nrrkeene/qmk_firmware/tree/master/keyboards/ergodox/keymaps/ordinary
 * AF Mar 2018 removed the references/calls to RBASE in the Base layer
 * AF 14/07/18 Added Arrow keys to RHS bottom row, instead of Ctrl, MEH etc;  RESET to RH top-right key
 * AF 23/07/18 Removed MT(MOD_LGUI,KC_PASTE) from LHS bottom row, as did not work, and messed up CTL-ALT-DEL
 * Added macros
 * 10/02/25 reformatted for 2025 QMK syntax.
 * removed Reverse Base Layer, commented out most old code, replaced with default
 * ADDED LT() TG() LAYER MEH, HYPER, functions.  
 * TODO Layers should not lock, unless LOCK key used, see ACTION_MACRO_TAP or a tap dance?
 * Symbol layer transparent for del, space etc..
 * additional MOUSE keys, CAPS WORD
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/******* Base Layer ****************************************************************************************************
 *
 * ,------------------------------------------------------.       ,------------------------------------------------------.
 * | Special `~ |   1  |   2  |   3  |   4  |   5  | ESC  |       |  -   |   6  |   7  |   8  |   9  |   0  | =+ Special |
 * |------------+------+------+------+------+-------------|       |------+------+------+------+------+------+------------|
 * | Media  Tab |   Q  |   W  |   E  |   R  |   T  |   [  |       |  ]   |   Y  |   U  |   I  |   O  |   P  | \|   Media |
 * |------------+------+------+------+------+------|      |       |      |------+------+------+------+------+------------|
 * | Symbol     |  ^A  |   S  |   D  |  ^F  |   G  |------|       |------|   H  |  ^J  |   K  |   L  |  ^;  | '"  Symbol |
 * |------------+------+------+------+------+------|Shift |       | Tab  |------+------+------+------+------+------------|
 * | Capitals   |   Z  |   X  |   C  |   V  |   B  | -Tab |       |      |   N  |   M  |   ,  |   .  |  /   |   Capitals |
 * `------------+------+------+------+------+-------------'       `-------------+------+------+------+------+------------'
 *      | LCtrl | Meh  |Hyper | LAlt | LGui |                                   | RGui | RAlt | Hyper|  Meh | RCtrl |
 *      | LCtrl | Meh  |Hyper | LAlt | LGui |                                   | RGui |  Up  | Down|  Left | Right |   from 14/7/18
 
 *      `-----------------------------------'                                   `-----------------------------------'
 *                                          ,-------------.       ,-------------.
 *                                          | Home | End  |       | Left | Right|
 *                                   ,------|------|------|       |------+------+------.
 *                                   |      |      | PgUp |       |  Up  |      |      |
 *                                   |Backsp| Del  |------|       |------| Enter| Space|
 *                                   |      |      | PgDn |       | Down |      |      |
 *                                   `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
// left hand
KC_GRV      ,KC_1           ,KC_2   ,KC_3   ,KC_4  ,KC_5  ,KC_ESC,
LT(MDIA,KC_TAB)  ,KC_Q      ,KC_W   ,KC_E   ,KC_R  ,KC_T  ,KC_LBRC,
TG(SYMB)    ,KC_A           ,KC_S   ,KC_D   ,KC_F  ,KC_G,
KC_LSFT     ,KC_Z           ,KC_X   ,KC_C   ,KC_V  ,KC_B  ,LSFT(KC_TAB),
KC_LCTL     ,KC_MEH   ,KC_HYPR, KC_LALT,KC_LGUI,
                                         KC_HOME,KC_END,
                                                KC_PGUP,
                                KC_BSPC,KC_DEL ,KC_PGDN,
                                                                  // right hand
                                                                KC_MINS ,KC_6 ,KC_7       ,KC_8   ,KC_9   ,KC_0       ,KC_EQL,
                                                                KC_RBRC ,KC_Y ,KC_U       ,KC_I   ,KC_O   ,KC_P       ,LT(MDIA,KC_BSLS),
                                                                        KC_H ,KC_J        ,KC_K   ,KC_L   ,KC_SCLN    ,LT(SYMB,KC_QUOT),
                                                                KC_TAB  ,KC_N ,KC_M       ,KC_COMM,KC_DOT ,KC_SLSH    ,KC_RSFT,
                                                                                KC_RGUI   ,KC_UP, KC_DOWN ,KC_LEFT    ,KC_RGHT,
                                                                KC_LEFT ,KC_RGHT,
                                                                KC_UP,
                                                                KC_DOWN ,KC_ENT ,KC_SPC
),

/******* Symbols Layer *************************************************************************************************
 *
 * ,-----------------------------------------------------.       ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  | Esc  |       |  -   |  F6  |  F7  |  F8  |  F9  |  F10 |           |
 * |-----------+------+------+------+------+-------------|       |------+------+------+------+------+------+-----------|
 * |           |   !  |   @  |   {  |   }  |   &  |  <   |       |  >   |   |  |   7  |   8  |   9  |   /  |           |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * |           |   #  |   $  |   (  |   )  |   `  |------|       |------|   /  |   4  |   5  |   6  |   *  |           |
 * |-----------+------+------+------+------+------|  '   |       |  "   |------+------+------+------+------+-----------|
 * |           |   %  |   ^  |   [  |   ]  |   ~  |      |       |      |   \  |   1  |   2  |   3  |   -  |           |
 * `-----------+------+------+------+------+-------------'       `-------------+------+------+------+------+-----------'
 *     |   ;   |   &  |   *  |   <  |   >  |                                   |   0  |   .  |   =  |   +  | Enter |
 *     `-----------------------------------'                                   `-----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         | |||| | |||| |       | |||| | |||| |
 *                                  ,------|------|------|       |------+------+------.
 *                                  | Plus | Equal| |||| |       | |||| | Under| Dash |
 *                                  |      |      |------|       |------| Score|      |
 *                                  |  +   |   =  |  !=  |       |  ->  |  _   |  -   |
 *                                  `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
// left hand
VRSN,     KC_F1       ,KC_F2        ,KC_F3   ,KC_F4   ,KC_F5   ,KC_ESC,
_______ ,KC_EXLM     ,KC_AT        ,KC_LCBR ,KC_RCBR ,KC_AMPR ,LSFT(KC_COMM),
_______ ,KC_HASH     ,KC_DLR       ,KC_LPRN ,KC_RPRN ,KC_GRV,
_______ ,KC_PERC     ,KC_CIRC      ,KC_LBRC ,KC_RBRC ,KC_TILD ,KC_QUOT,
KC_SCLN ,KC_AMPR     ,KC_ASTR ,LSFT(KC_COMM),LSFT(KC_DOT),
                                                    _______,_______,
                                                            KC_NO,
                                             KC_PLUS ,KC_EQL,_______,
                                                                 // right hand
                                                                _______,KC_F6,     KC_F7 ,KC_F8  ,KC_F9 ,KC_F10  ,_______,
                                                                _______,KC_PIPE,   KC_P7  ,KC_P8   ,KC_P9  ,KC_PSLS ,_______,
                                                                            KC_SLSH,    KC_P4  ,KC_P5   ,KC_P6  ,KC_PAST ,_______,
                                                                _______,KC_BSLS,  KC_P1  ,KC_P2   ,KC_P3  ,KC_PMNS ,_______,
                                                                                        KC_P0  ,KC_PDOT ,KC_PEQL,KC_PPLS ,KC_PENT,
                                                                _______,  _______,
                                                                _______,
                                                                _______  ,_______,_______
),

/******* Media Layer *******************************************************************************************************
 *
 * ,---------------------------------------------------------------.    ,---------------------------------------------------------------.
 * |      |   F11   |   F12   |   F13   |   F14   |   F15   | Esc  |    | |||| |   F16   |   F17   |   F18   |   F19   |   F20   |      |
 * |------+---------+---------+---------+---------+----------------|    |------+---------+---------+---------+---------+---------+------|
 * |      |Shut Down|MouseUpLf|Mouse Up |MouseUpRg|Volume Up|Scroll|    |Scroll|PrintScrn|   Home  |    Up   |   PgUp  |   Mail  |      |
 * |------+---------+---------+---------+---------+---------|  Up  |    |  Up  |---------+---------+---------+---------+---------+------|
 * |      |  Sleep  |MouseLeft|MouseDown|MouseRght|Volume Dn|------|    |------| Num Lock|   Left  |   Down  |   Right | MyComp  |      |
 * |------+---------+---------+---------+---------+---------|Scroll|    |Scroll|---------+---------+---------+---------+---------+------|
 * |      |  ||||   |MouseDnLf|MouseDown|MouseDnRg|  Mute   | Down |    | Down |  ||||   |   End   |   Down  |   PgDn  |  ||||   |      |
 * `------+---------+---------+---------+---------+----------------'    `----------------+---------+---------+---------+---------+------'
 *  | ||| |  ||||   |  MClick | LClick  |  R Click|                                      |  Insert |   Del   |   ||||  |  ||||   | ||| |
 *  `---------------------------------------------'                                      `---------------------------------------------'
 *                                                   ,-------------.    ,-------------.
 *                                                   | Stop |Refrsh|    | Prev | Next |
 *                                            ,------|------|------|    |------+------+------.
 *                                            |Brwser|Brwser|Search|    |VolUp |      |      |
 *                                            |Back  | Fwd  |------|    |------| Stop | Play-|
 *                                            |      |      | Home |    |VolDn |      | Pause|
 *                                            `--------------------'    `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
// left hand
 _______ ,KC_F11   ,KC_F12  ,KC_F13   ,KC_F14  ,KC_F15  ,KC_ESC
,_______ ,KC_PWR   ,_______  ,KC_MS_U  ,_______  ,KC_VOLU ,KC_WH_U
,_______ ,KC_SLEP  ,KC_MS_L ,KC_MS_D  ,KC_MS_R ,KC_VOLD
,_______ ,KC_NO    ,_______  ,KC_MS_D  ,_______  ,KC_MUTE ,KC_WH_D
,KC_NO ,KC_NO   ,KC_BTN3 ,KC_BTN1  ,KC_BTN2
                                               ,KC_WSTP ,KC_WREF
                                                        ,KC_WSCH
                                      ,KC_WBAK ,KC_NO   ,KC_WHOM
                                                                     // right hand
  //                                                                   ,KC_NO    ,KC_F16  ,KC_F17       ,KC_F18       ,KC_F19  ,KC_F20  ,_______
                                                                     ,QK_BOOT  ,KC_F16  ,KC_F17       ,KC_F18       ,KC_F19  ,KC_F20  ,_______
                                                                     ,KC_WH_U  ,KC_PSCR ,KC_HOME      ,KC_UP        ,KC_PGUP ,KC_MAIL ,_______
                                                                               ,KC_NUM  ,KC_LEFT      ,KC_DOWN      ,KC_RIGHT,KC_MYCM ,_______
                                                                     ,KC_WH_D  ,KC_NO   ,KC_END       ,KC_DOWN      ,KC_PGDN ,KC_NO   ,_______
                                                                                        ,KC_INS       ,KC_DEL       ,KC_NO   ,KC_NO   ,KC_NO
                                                                     ,KC_MPRV  ,KC_MNXT
                                                                     ,KC_VOLU
                                                                     ,KC_VOLD  ,KC_MSTP ,KC_MPLY
),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
  }
  return true;
}

bool led_update_user(led_t led_state) {
    // stub any kb level behaviour
    return false;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(layer_state)) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

// const uint16_t PROGMEM fn_actions[] = {
//      // the faux shift keys are implemented as macro taps
//      [LSymb] = ACTION_MACRO_TAP(LSymb)
//     ,[LMdia] = ACTION_MACRO_TAP(LMdia)
//     ,[LSpec] = ACTION_MACRO_TAP(LSpec)
//     ,[RSymb] = ACTION_MACRO_TAP(RSymb)
//     ,[RMdia] = ACTION_MACRO_TAP(RMdia)
//     ,[RSpec] = ACTION_MACRO_TAP(RSpec)
// };

// uint16_t symb_shift = 0;
// uint16_t mdia_shift = 0;
// uint16_t spec_shift = 0;

// bool mdia_lock = false;
// bool symb_lock = false;

// // AF see https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md
// // this is the old way to call macros
// // const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch(keycode) {
//         // There are two shift keys for each layer so we increment a layer_shift var when one
//         // is pressed and decrement when one is released. The shift counts are bound between 0 and 2
//         // only because sometimes rapid pressing led to irregular events; this way the states
//         // are self healing during use.

//         case LSymb:                                               //
//         if (record->event.pressed) {                              // when the LSymb button is pressed
//             if(++symb_shift > 2) symb_shift = 2;                  // increment the symb shift count, max two
//             if(spec_shift) symb_lock = !symb_lock;                // if the Special layer is on, toggle the shift lock
//             layer_on(SYMB);                                       // in any case, turn on the Symbols layer
//         } else {                                                  // when the LSymb button is released
//             if(--symb_shift < 0) symb_shift = 0;                  // decrement the shift count, minimum zero
//             if((!symb_shift) && (!symb_lock)) layer_off(SYMB);    // if both shifts are released and the lock is off, turn off the Symbols layer
//         }
//         break;

//         case LMdia:
//         if (record->event.pressed) {
//            if (record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
//                 register_code(KC_TAB);
//             } else {
//                 if(spec_shift) mdia_lock = !mdia_lock;
//                 if(++mdia_shift > 2) mdia_shift = 2;
//                 layer_on(MDIA);
//             }
//         } else {
//             if(record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
//                 unregister_code(KC_TAB);
//             } else {
//                 if(--mdia_shift < 0) mdia_shift = 0;
//                 if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
//             }
//         }
//         break;

//         // case LSpec:
//         // if (record->event.pressed) {                                     // when the LSpec button is pressed
//         //     if(symb_shift) symb_lock = !symb_lock;                       // if another layer button is engaged, then
//         //     else if(mdia_shift) mdia_lock = !mdia_lock;                  // lock that layer, be it caps or symb or mdia
//         //     else if (record->tap.count && !record->tap.interrupted && (!spec_shift)) {
//         //         register_code(KC_GRV);                                   // otherwise, if it's an uninterrupted tap, emit a char
//         //     } else {
//         //         if(++spec_shift > 2) spec_shift = 2;
//         //         layer_on(SPEC);                                          // otherwise, turn on the Special layer
//         //     }
//         // } else {
//         //     if(record->tap.count && !record->tap.interrupted && (!spec_shift)) {
//         //         unregister_code(KC_GRV);
//         //     } else {
//         //         if(--spec_shift < 0) spec_shift = 0;
//         //         if(!spec_shift) layer_off(SPEC);
//         //     }
//         // }
//         // break;

//         case RSymb:
//         if (record->event.pressed) {
//             if (record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift)) {
//                 register_code(KC_QUOT);
//             } else {
//                 if(++symb_shift > 2) symb_shift = 2;
//                 if(spec_shift) symb_lock = !symb_lock;
//                 layer_on(SYMB);
//             }
//         } else {
//             if(record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift)) {
//                 unregister_code(KC_QUOT);
//             } else {
//                 if(--symb_shift < 0) symb_shift = 0;
//                 if((!symb_shift) && (!symb_lock)) layer_off(SYMB);
//             }
//         }
//         break;

//         case RMdia:
//         if (record->event.pressed) {
//             if (record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
//                 register_code(KC_BSLS);
//             } else {
//                 if(++mdia_shift > 2) mdia_shift = 2;
//                 if(spec_shift) mdia_lock = !mdia_lock;
//                 layer_on(MDIA);
//             }
//         } else {
//             if(record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift)) {
//                 unregister_code(KC_BSLS);
//             } else {
//                 if(--mdia_shift < 0) mdia_shift = 0;
//                 if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
//             }
//         }
//         break;

//         // case RSpec:
//         // if (record->event.pressed) {
//         //     if(symb_shift) symb_lock = !symb_lock;
//         //     else if(mdia_shift) mdia_lock = !mdia_lock;
//         //     else if (record->tap.count && !record->tap.interrupted && (!spec_shift)) {
//         //         register_code(KC_EQL);
//         //     } else {
//         //         if(++spec_shift > 2) spec_shift = 2;
//         //         layer_on(SPEC);
//         //     }
//         // } else {
//         //     if(record->tap.count && !record->tap.interrupted && (!spec_shift)) {
//         //         unregister_code(KC_EQL);
//         //     } else {
//         //         if(--spec_shift < 0) spec_shift = 0;
//         //         if(!spec_shift) layer_off(SPEC);
//         //     }
//         // }
//         // break;

//         case NotEq:
//         if (record->event.pressed) {
//             return MACRO( I(10), D(LSFT), T(1), U(LSFT), T(EQL), END  ); // !=
//         }
//         break;

//         case GrtEq:
//         if (record->event.pressed) {
//             return MACRO( I(10), D(LSFT), T(COMM), U(LSFT), T(EQL), END  ); // <=
//         }
//         break;

//         case LesEq:
//         if (record->event.pressed) {
//             return MACRO( I(10), D(LSFT), T(DOT), U(LSFT), T(EQL), END  ); // >=
//         }
//         break;

//         case DeRef:
//         if (record->event.pressed) {
//             return MACRO( I(10), T(MINS), D(LSFT), T(DOT), U(LSFT), END  ); // ->
//         }
//         break;

//         // mouse diagonals

//         case MUL: // mouse up left
//         if (record->event.pressed) {
//             mousekey_on(KC_MS_UP);
//             mousekey_on(KC_MS_LEFT);
//             mousekey_send();
//         } else {
//             mousekey_off(KC_MS_UP);
//             mousekey_off(KC_MS_LEFT);
//             mousekey_send();
//         }
//         break;

//         case MUR: // mouse up right
//         if (record->event.pressed) {
//             mousekey_on(KC_MS_UP);
//             mousekey_on(KC_MS_RIGHT);
//             mousekey_send();
//         } else {
//             mousekey_off(KC_MS_UP);
//             mousekey_off(KC_MS_RIGHT);
//             mousekey_send();
//         }
//         break;

//         case MDL: // mouse down left
//         if (record->event.pressed) {
//             mousekey_on(KC_MS_DOWN);
//             mousekey_on(KC_MS_LEFT);
//             mousekey_send();
//         } else {
//             mousekey_off(KC_MS_DOWN);
//             mousekey_off(KC_MS_LEFT);
//             mousekey_send();
//         }
//         break;

//         case MDR: // mouse down right
//         if (record->event.pressed) {
//             mousekey_on(KC_MS_DOWN);
//             mousekey_on(KC_MS_RIGHT);
//             mousekey_send();
//         } else {
//             mousekey_off(KC_MS_DOWN);
//             mousekey_off(KC_MS_RIGHT);
//             mousekey_send();
//         }
//         break;
//     }
//     return true;
// }

// Runs just one time when the keyboard initializes.
// void matrix_init_user(void) {
	// AF 14/7/18 added these 4 lines
	// ergodox_led_init;
	//ergodox_right_led_1_on();
	//ergodox_right_led_2_on();
	//ergodox_right_led_3_on();
// };

// Runs constantly in the background, in a loop.
// rewrite with https://docs.qmk.fm/feature_layers#example-layer-state-set-implementation
// void matrix_scan_user(void) {
//     // shift or caps lock turns on red light
//     if((keyboard_report->mods & MOD_BIT(KC_LSFT))
//     || (keyboard_report->mods & MOD_BIT(KC_RSFT))
//     || (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) {
//         ergodox_right_led_1_on();
//     } else {
//         ergodox_right_led_1_off();
//     }

//     // Symbol layer turns on green light
//     if(layer_state & (1UL<<SYMB)) {
//         ergodox_right_led_2_on();
//     } else {
//         ergodox_right_led_2_off();
//     }

//     // Media layer turns on blue light
//     if(layer_state & (1UL<<MDIA)) {
//         ergodox_right_led_3_on();
//     } else {
//         ergodox_right_led_3_off();
//     }
// };
