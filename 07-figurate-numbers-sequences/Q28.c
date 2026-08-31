#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(void) {
    int size = 1001;
    long long sum = 1;

    for (int n = 3; n <= size; n += 2) {
        int square = n * n;
        sum += square;
        sum += square - (n - 1);
        sum += square - 2 * (n - 1);
        sum += square - 3 * (n - 1);
    }

    printf("Sum of diagonals: %lld\n", sum);
    return 0;
}