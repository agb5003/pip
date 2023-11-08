#include <stdio.h>
#include <math.h>

typedef struct {
    double x_coord;
    double y_coord;
} point;

double get_dist(point a, point b) {
    return sqrt(pow(a.x_coord - b.x_coord,2) + pow(a.y_coord - b.y_coord, 2));
}

int main() {
    point a = {1.0, 1.0};
    point b = {5.0, 4.0};

    double distance = get_dist(a, b);

    printf("a = (%lf, %lf)\n", a.x_coord, a.y_coord);
    printf("b = (%lf, %lf)\n", b.x_coord, b.y_coord);
    printf("Distance between the points is %lf\n", distance);
}
