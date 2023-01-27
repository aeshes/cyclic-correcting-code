#pragma once

#define CODE_LENGTH 15
#define MESSAGE_LENGTH 7
#define ERROR_CORRECTION_COUNT 2
#define GENERATOR 0x1D1				/* Generating polynomial g(x) = x^6 + x^5 + x^4 + x^3 + x^2 + x + 1 */
#define CODE_BITMASK 0x7FFF