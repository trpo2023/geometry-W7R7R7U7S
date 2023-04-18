#include <stdio.h>
#include <stdlib.h>

#include <libgeometry/bugs.h>

#define RED_FLASH "\e[5;31m"
#define END "\e[0m"
#define MAX 100

void output_bugs(int errors, int num, char* ch)
{
    for (int i = 0; i < num; i++) {
        putchar(' ');
    }
    printf("^\n");

    switch (errors) {
    case BUG_NAME:
        printf("An error %d was found in the input line %s'Circle'%s\n",
               num,
               RED_FLASH,
               END);
        break;
    case BUG_STAPLES:
        if (*ch == ')') {
            printf("An error %d was found in the input line %s')'%s\n",
                   num,
                   RED_FLASH,
                   END);
            break;
        } else {
            printf("An error %d was found in the input line %s'('%s\n",
                   num,
                   RED_FLASH,
                   END);
            break;
        }
    case BUG_STAPLES_2:
        printf("An error %d was found in the input line %s')'%s\n",
               num,
               RED_FLASH,
               END);
        break;
    case BUG_NUMBER:
        printf("An error %d was found in the input line %s'double'%s\n",
               num,
               RED_FLASH,
               END);
        break;
    case BUG_UNIDENTIFIED_VARIABLES:
        printf("An error %d was found in the input line %s'variable'%s\n",
               num,
               RED_FLASH,
               END);
        break;
    case BUG_EXPECT_COMMA:
        printf("An error %d was found in the input line %s','%s\n",
               num,
               RED_FLASH,
               END);
        break;
    case BUG_EXTRA_POINT:
        printf("An error %d was found in the input line %s'.'%s\n",
               num,
               RED_FLASH,
               END);
        break;
    }
}
