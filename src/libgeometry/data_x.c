#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/bugs.h>
#include <libgeometry/data_x.h>

double x_data(char* arr, int* num)
{
    char free_space[20];
    int i = 0;

    while (!isdigit(arr[*num]) && arr[*num] != '-') {
        if (arr[*num] == '(') {
            *num += 1;
        } else {
            if (arr[*num] == ')') {
                output_bugs(BUG_STAPLES, *num, &arr[*num]);
                exit(1);
            }
            if (arr[*num] == ' ') {
                output_bugs(BUG_STAPLES, *num, &arr[*num]);
                exit(1);
            } else {
                output_bugs(BUG_NUMBER, *num, NULL);
                exit(1);
            }
        }
    }

    while (isdigit(arr[*num]) || arr[*num] == '-' || arr[*num] == '.') {
        free_space[i] = arr[*num];
        i++;
        *num += 1;
    }

    if (arr[*num] != ' ') {
        output_bugs(BUG_UNIDENTIFIED_VARIABLES, *num, NULL);
        exit(1);
    }
    char* dumpster;
    return strtod(free_space, &dumpster);
}

