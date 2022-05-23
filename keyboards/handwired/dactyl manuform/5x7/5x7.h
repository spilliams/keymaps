#pragma once

#include "dactyl_manuform.h"

#define XX KC_NO

// Rows 1-5 are LH, 6-0 are RH
// Cols A-H are shared
#define LAYOUT_5x7( \
    A2, A3, A4, F5, A5, C5, E5,                 G0, F0, B0, A0, A9, A8, A7, \
    B2, B3, B4, B5, D5, G5, H5,                 H0, E0, D0, C0, B9, B8, B7, \
    C2, C3, C4, D4, E4, F4, H4,                 H9, F9, E9, D9, C9, C8, C7, \
    D2, E2, D3, E3, F3, H3,   E1, D1,     D6, E6,   G8, F8, E8, D8, E7, D7, \
            F2, G2, H2,   A1, B1, C1,     C6, B6, A6,   H7, G7, F7 \
) { \
    { A1, B1, C1, D1, E1, XX, XX, XX }, \
    { A2, B2, C2, D2, E2, F2, G2, H2 }, \
    { A3, B3, C3, D3, E3, F3, XX, H3 }, \
    { A4, B4, C4, D4, E4, F4, XX, H4 }, \
    { A5, B5, C5, D5, E5, F5, G5, H5 }, \
    { A6, B6, C6, D6, E6, XX, XX, XX }, \
    { A7, B7, C7, D7, E7, F7, G7, H7 }, \
    { A8, B8, C8, D8, E8, F8, G8, XX }, \
    { A9, B9, C9, D9, E9, F9, XX, H9 }, \
    { A0, B0, C0, D0, E0, F0, G0, H0 } \
}
