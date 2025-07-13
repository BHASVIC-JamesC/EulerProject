#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void SieveOfEratosthenes(int n, bool* prime, long long int* primes, int* totalPrimes) {
    memset(prime, true, (n + 1) * sizeof(bool));
    prime[0] = prime[1] = false;
    int count = 0;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes[count++] = p;
        }
    }
    *totalPrimes = count;
}

int main(void) {
    int limit = 1000000;
    bool* prime = malloc((limit + 1) * sizeof(bool));
    long long int* primes = malloc(80000 * sizeof(long long int));  // Enough primes
    int totalPrimes = 0;

    SieveOfEratosthenes(limit, prime, primes, &totalPrimes);

    int maxLength = 0;
    int resultPrime = 0;

    for (int start = 0; start < totalPrimes; start++) {
        long long int sum = 0;
        for (int end = start; end < totalPrimes; end++) {
            sum += primes[end];
            if (sum > limit) {
                break;
            }
            if (prime[sum] && (end - start + 1) > maxLength) {
                maxLength = end - start + 1;
                resultPrime = sum;
            }
        }
    }

    printf("Prime: %d\nLength: %d\n", resultPrime, maxLength);

    free(primes);
    free(prime);
    return 0;
}
