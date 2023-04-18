#include <math.h>
#include <stdio.h>

#include <libgeometry/bugs.h>
#include <libgeometry/data_x.h>
#include <libgeometry/data_y.h>
#include <libgeometry/output_message.h>
#include <libgeometry/radius_data.h>

void to_lower(char* str, int ch)
{
    for (int i = 0; i < ch; i++) {
        str[i] = tolower(str[i]);
    }
}

void empty(char* arr, int* num)
{
    *num += 1;
    while (arr[*num] != '\n' && arr[*num] != EOF) {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            output_bugs(BUG_UNIDENTIFIED_VARIABLES, *num, NULL);
            exit(1);
        }
    }
}

struct Point find_center(char* arr, int* num)
{
    struct Point Center;

    Center.x = x_data(arr, num);
    Center.y = y_data(arr, num);

    return Center;
}

struct Circle find_out_circle(struct Point* Center, char* arr, int* num)
{
    struct Circle circle;

    circle.center.x = Center->x;
    circle.center.y = Center->y;
    circle.radius = radius_data(arr, num);

    return circle;
}

void output_circle_message(struct Circle* circle)
{
    printf("\ncircle(%.2f %.2f, %.2f)\n",
           circle->center.x,
           circle->center.y,
           circle->radius);
    printf("perimeter: %.4f\n", (2 * M_PI * circle->radius));
    printf("area: %.4f\n", ((circle->radius * circle->radius) * M_PI));
}
