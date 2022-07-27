#include "headers/dbc.h"

int convBinDec (lli bin) {
    int dec = 0;

    for (lli pow10 = 10, pow2 = 1, digit_value = 0; bin / (pow10 / 10) >= 1; pow10 *= 10, pow2 *= 2) {
        digit_value = bin % pow10;
        dec += (bool) digit_value * pow2;

        bin -= digit_value;
    }

    return dec;
}

lli convDecBin (int dec) {
    long long int bin = 0;

    for (int pow10 = 1; ; pow10 *= 10) {
        bin += (dec % 2) * pow10;
        if ((dec /= 2) == 0) break;
    }

    return bin;
}
