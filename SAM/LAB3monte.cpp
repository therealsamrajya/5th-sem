#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_POINTS 1000000

int main() {
    int inside_circle = 0;
    double x, y;

    // Seed the random number generator with the current time
    srand(time(NULL));

    for (int i = 0; i < TOTAL_POINTS; i++) {
        // Generate random points in the range [0, 1]
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;

        // Check if the point is inside the unit circle
        if (x * x + y * y <= 1) {
            inside_circle++;
        }
    }

    // Estimate the value of pi using the ratio of points inside the circle to total points
    double estimated_pi = 4.0 * inside_circle / TOTAL_POINTS;

    printf("Estimated value of pi: %lf\n", estimated_pi);

    return 0;
}

