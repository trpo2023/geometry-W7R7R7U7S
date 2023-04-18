#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

struct Circle {
    struct Point center;
    double radius;
};

void to_lower(char* str, int ch);
void empty(char* arr, int* num);

struct Point find_center(char* arr, int* num);
struct Circle find_out_circle(struct Point* Center, char* arr, int* num);

void output_circle_message(struct Circle* circle);
