//
// Created by Uno on 07/01/2022.
//

#include "essentials.h"
#include <stdio.h>

void error(char *error_message) {
    printf("\033[0;31mERROR: %s\033[0m\n", error_message);
}
