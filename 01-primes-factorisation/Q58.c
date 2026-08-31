#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRIME 700000000

bool* prime;



void SieveOfEratosthenes(int n) {
    prime = malloc((n + 1) * sizeof(bool));
    if (prime == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    memset(prime, true, (n + 1) * sizeof(bool));
    prime[0] = prime[1] = false;

    for (long long p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (long long i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
}

int main(void) {
    SieveOfEratosthenes(MAX_PRIME);

    int side_length = 1;
    int number = 1;
    int step = 2;
    int prime_count = 0;
    int total_diagonals = 1;

    while (1) {
        for (int i = 0; i < 4; i++) {
            number += step;
            if (prime[number]) {
                prime_count++;
            }
        }
        total_diagonals += 4;
        side_length += 2;

        if ((float)prime_count / total_diagonals < 0.1) {
            printf("%d\n", side_length);
            break;
        }
        step += 2;
    }

    free(prime);
    return 0;
}
