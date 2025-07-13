#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool binarySearch(int start, int end, long long int target, long long int* arr);
void sieve(int limit, int targetCount, long long int* arr);

int main(void) {
    int total = 0;
    int count = 1000000;
    long long int* arr = (long long int*)malloc(sizeof(long long int) * count);
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    sieve(16000000, count, arr);  // limit is slightly above 15,485,863

    for (int y = 0; y < count; y++) {
        long long int reverse = 0;
        long long int temp = arr[y];
        while (temp > 0) {
            int digit = temp % 10;
            reverse = reverse * 10 + digit;
            temp /= 10;
        }

        if (arr[y] != reverse && arr[y] < reverse &&
            binarySearch(0, count - 1, reverse, arr)) {
            printf("%lld %lld\n", arr[y], reverse);
            total++;
        }
    }

    printf("total: %d\n", total);
    free(arr);
    return 0;
}

void sieve(int limit, int targetCount, long long int* arr) {
    bool* prime = (bool*)malloc(sizeof(bool) * (limit + 1));
    if (prime == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i <= limit; i++) prime[i] = true;

    for (int x = 2; x * x <= limit; x++) {
        if (prime[x]) {
            for (int p = x * x; p <= limit; p += x) {
                prime[p] = false;
            }
        }
    }

    int count = 0;
    for (int j = 2; j <= limit && count < targetCount; j++) {
        if (prime[j]) {
            arr[count] = (long long int)j * j;
            count++;
        }
    }

    free(prime);
}

bool binarySearch(int start, int end, long long int target, long long int* arr) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
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
