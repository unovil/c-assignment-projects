/*  --------------------------------
    write a program containing the following bit fields
    in a struct representing an onscreen box

    characteristics:
    - box can be opaque/transparent (1 bit)
        [1: opaque, 0: transparent]
    - fill color can be red, green, blue, yellow, cyan,
        magenta, black, white (3 bits)
        [000: black, 001: red, 010: green, 011: yellow,
         100: blue, 101: magenta, 110: cyan, 111: white]
    - border can be shown/hidden (1 bit)
        [1: shown, 0: hidden]
    - border color is selected from same palette
        for fill (3 bits)
    - border can be solid/dotted/dashed (2 bits)
        [0: solid, 1: dotted, 2: dashed]

    padding
    - use padding to place fill-related info on 1 byte,
        border-related info on another byte
    - without padding, structure would have size of 10 bits
        should be 16 bits with padding
    
    -------------------------------- */
#include <stdio.h>

enum boxOpacity {TRANSPARENT, OPAQUE};
enum color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
enum borderShown {HIDDEN, SHOWN};
enum borderStyle {SOLID, DOTTED, DASHED};

const char *COLORS[8]= {
        "black",
        "red",
        "green",
        "yellow",
        "blue",
        "magenta",
        "cyan",
        "white"
};

struct OnScreenBox {
    unsigned int boxOpacity:1;
    unsigned int fillColor:3;
    unsigned int :4;

    unsigned int borderShow:1;
    unsigned int borderColor:3;
    unsigned int borderStyle:2;
    unsigned int :2;
};

void show_settings(struct OnScreenBox box) {
    // box opacity
    printf("Box is %s\n", box.boxOpacity? "transparent" : "opaque");
    // fill color
    printf("Box color is %s\n", COLORS[box.fillColor]);
    // border shown
    printf("Border is %s\n", box.borderShow? "hidden" : "shown");
    // border color
    printf("Border color is %s\n", COLORS[box.borderColor]);
    // border style
    printf("Border style is ");
    switch (box.borderStyle) {
        case 0:
            printf("solid\n");
            break;
        case 1:
            printf("dotted\n");
            break;
        case 2:
            printf("dashed\n");
            break;
        default:
            printf("in the wrong format\n");
            break;
    }
}

int main() {
    struct OnScreenBox box1 = {
        .boxOpacity = TRANSPARENT,
        .fillColor = BLACK,
        .borderShow = HIDDEN,
        .borderColor = BLACK,
        .borderStyle = SOLID,
    };

    printf("Original settings:\n");
    show_settings(box1);

    box1.boxOpacity = OPAQUE;
    box1.fillColor = CYAN;
    box1.borderShow = SHOWN;
    box1.borderColor = MAGENTA;
    box1.borderStyle = DASHED;

    printf("\nModified settings:\n");
    show_settings(box1);

    return 0;
}