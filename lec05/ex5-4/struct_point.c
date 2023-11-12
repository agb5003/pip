#include <stdio.h>
#include <math.h>

typedef struct {
    double x_coord;
    double y_coord;
} point;

double get_dist(point a, point b) { // Distance between point a and b
    return sqrt(pow(a.x_coord - b.x_coord, 2) + pow(a.y_coord - b.y_coord, 2));
}

double get_angle(point pointA, point pointB) {
    double deltaY = pointA.y_coord - pointB.y_coord;
    double deltaX = pointA.x_coord - pointB.x_coord;
    double radians = (atan(deltaY / deltaX)); // Get angle in radians
    return radians * 180 / M_PI; // Convert radian to degrees
}

int main() {
    point a = {1.0, 1.0};
    point b = {5.0, 4.0};

    double distance = get_dist(a, b);

    printf("a = (%lf, %lf)\n", a.x_coord, a.y_coord);
    printf("b = (%lf, %lf)\n", b.x_coord, b.y_coord);
    printf("Distance between the points is %lf units.\n", distance);

    double x_angle = get_angle(a, b);
    printf("Angle formed by line and x-axis is %lf degrees.\n", x_angle);
    printf("Angle formed by line and y-axis is %lf degrees.\n", 90 - x_angle);
}