#include <stdio.h>
#include <math.h>

int factors(unsigned long long int N);
int triangles(unsigned long long int n);

int main(void) {
    for(int i = 1;i<=50000;i++) {
        unsigned long long int ans = triangles(i);
        int factor = factors(ans);
        if(factor>500) {
            printf("Triangle Number: %llu\n", ans);
            printf("Number of factors: %d\n", factors(ans));
            break;
        }

    }
    return 0;
}

// Function to count the number of factors of N using iteration
int factors(unsigned long long int N) {
    int total = 0;
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            if (i * i == N) {
                total += 1;  // Perfect square factor
            } else {
                total += 2;  // Pair of factors
            }
        }
    }
    return total;
}

// Function to compute the nth triangular number iteratively
int triangles(unsigned long long int n) {
    return (n * (n + 1)) / 2;
}
