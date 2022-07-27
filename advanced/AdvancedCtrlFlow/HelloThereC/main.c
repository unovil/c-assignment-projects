#include <setjmp.h>
#include <stdio.h>

jmp_buf buf;

int main(void) {
    int i = setjmp(buf);
    printf("i = %d\n", i);
    longjmp(buf, 42);
    printf("Does this line get printed?\n");
    return 0;
}