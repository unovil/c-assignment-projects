#include <stdio.h>  // input/output

/// challenge 1: declaration
/*
create a program with following variables
    1. int with block scope and temporary storage
    2. global double only accessible in file
    3. global float accessible to entire program
    4. local float with permanent storage
    5. int in register
    6. function accessible to file defined
*/

static double file_inaccessible;   // 2.
/*extern*/ double file_accessible; // 3.


static void static_func(void)       // 6.
{
    static float local_permanent;  // 4.
}


int main(void)
{
    register int register_var;     // 5.
    /*auto*/ int block_temporary;  // 1.

    return 0;
}
