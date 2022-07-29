//
// Created by Uno on 07/29/2022.
//

#include "print.h"

// error printing function
void err_printf(char *fmt, ...) {
    char *toPass = calloc(1024, sizeof(char));
    char *errmsg = "\033[31;1mERROR: \033[0m\033[31m";
    char *defcolor = "\033[0m";

    strncat(toPass, errmsg, 1024);
    strncat(toPass, fmt,    1024 - strlen(errmsg) - strlen(defcolor));
    strncat(toPass, defcolor, 1024 - strlen(errmsg));

    va_list args;
    va_start(args, fmt);
    vprintf(toPass, args);
    va_end(args);
}
