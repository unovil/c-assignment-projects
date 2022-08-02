#include <stdio.h>
#include "headers/vmath.h"
#include "headers/print.h"


int main() {
    // testing variadic sum functions
    printf("The sum of 152, 38, 52, and 85 is %d\n", i_vsum(152,38,52,85, 0));
    printf("The sum of 200.5, 70.2228, 10.229, and 100.0 is %.7lf\n\n", d_vsum(200.5, 70.2228, 10.229, 100.0, 0));

    // testing variadic mean functions
    printf("The mean of 152, 38, 52, and 85 is %.3f\n", i_vmean(152,38,52,85, 0));
    printf("The mean of 200.5, 70.2228, 10.229, and 100.0 is %.7lf\n\n", d_vmean(200.5, 70.2228, 10.229, 100.0, 0));

    // testing variadic minmax functions
    printf("The smallest of 152, 38, 52, and 85 is %d\n", i_vext(E_MIN, 152,38,52,85, 0));
    printf("The largest of 152, 38, 52, and 85 is %d\n", i_vext(E_MAX, 152,38,52,85, 0));
    printf("The smallest of 200.5, 70.2228, 10.229, and 100.0 is %.4lf\n", d_vext(E_MIN, 200.5, 70.2228, 10.229, 100.0, 0));
    printf("The largest of 200.5, 70.2228, 10.229, and 100.0 is %.4lf\n\n", d_vext(E_MAX, 200.5, 70.2228, 10.229, 100.0, 0));

    // testing error printing function
    printf("What a lovely day!\n");
    err_printf("File X is not working. Please check, thank you.\n");
    printf("Now where was I?\n");

    return 0;
}