#include <stdio.h>

#define RED_FLASH "\e[5;31m"
#define END "\e[0m"

enum Bugs {
    BUG_NAME,
    BUG_STAPLES,
    BUG_NUMBER,
    BUG_UNIDENTIFIED_VARIABLES,
    BUG_EXPECT_COMMA,
    BUG_STAPLES_2,
    BUG_EXTRA_POINT,
};

void output_bugs(int errors, int num, char* ch);

