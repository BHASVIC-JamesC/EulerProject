#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool binarysearch(long long int* arr, int start, int end, long long int target);

int main(void) {
    long long int* pentagonals = malloc(100000 * sizeof(long long int));
    long long int* triangles = malloc(100000 * sizeof(long long int));
    long long int* hexagonals = malloc(100000 * sizeof(long long int));

    for (int i = 1; i <= 100000; i++) {
        pentagonals[i - 1] = (long long int)i * (3 * i - 1) / 2;
        triangles[i - 1] = (long long int)i * (i + 1) / 2;
        hexagonals[i - 1] = (long long int)i * (2 * i - 1);
    }

    for (int x = 0; x < 100000; x++) {
        if (binarysearch(pentagonals, 0, 99999, triangles[x]) &&
            binarysearch(hexagonals, 0, 99999, triangles[x])) {
            printf("%lld\n", triangles[x]);
            }
    }

    free(pentagonals);
    free(triangles);
    free(hexagonals);

    return 0;
}

bool binarysearch(long long int* arr, int start, int end, long long int target) {
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}
