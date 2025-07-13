#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

bool primeFactors(long long int n, long long int* primes);

void SieveOfEratosthenes(int n, long long int* primes) {
    bool prime[n + 1];
    memset(prime, true, (n + 1) * sizeof(bool));
    int count = 0;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p] && count < 100000) {
            primes[count++] = (long long int)p;
        }
    }

    // Optional: Null-terminate the prime list
    primes[count] = 0;
}

bool primeFactors(long long int n, long long int* primes) {
    int count = 0;
    int begin = 0;
    while (n != 1) {
        long long int p = primes[begin++];
        if (n % p == 0) {
            count++;
            while (n % p == 0) {
                n /= p;
            }
        }
    }
    return count == 4;
}

int main(void) {
    long long int* primes = malloc(100000 * sizeof(long long int));
    SieveOfEratosthenes(1299710, primes);  // 104730 is the 10000th prime

    for (int i = 210; i < 1000000; i+=3) {
        if (primeFactors(i, primes) &&
            primeFactors(i + 1, primes) &&
            primeFactors(i + 2, primes) &&
            primeFactors(i + 3, primes)) {
            printf("First number in the sequence: %d\n", i);
            break;
            }
    }

    free(primes);
    return 0;
}
