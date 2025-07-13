#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

bool are_permutations(int a, int b, int c);

void SieveOfEratosthenes(int n, int* primes) {
    bool prime[n + 1];
    memset(prime, true, (n + 1) * sizeof(bool));
    int count = 0;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 1000; p < 10000; p++) {
        if (prime[p]) {
            primes[count++] = p;
        }
    }

}


int main(void) {
    int primes[1061];
    SieveOfEratosthenes(10000,primes);
    for(int i = 0;i<1061;i++) {
        int start = 1;

        while(start<4000) {
            int num1 = primes[i];
            int num2 = primes[i] + start;
            int num3 = primes[i] + 2*start;
            if(are_permutations(num1,num2,num3) && num2<10000 && num3<10000) {
                bool state1 = false;
                bool state2 = false;
                for(int x = 0;x<1061;x++) {
                    if(num2 == primes[x]) {
                        state1 = true;
                    }
                    else if(num3 == primes[x]) {
                        state2 = true;
                    }
                }
                if(state1 == true && state2 == true){
                    printf("%d,%d,%d",num1,num2,num3);
                    printf("\nstart:%d",start);
                    printf("\n%d%d%d",num1,num2,num3);
                    printf("\n");
                }
            }
            start++;
        }

    }
    return 0;
}
bool are_permutations(int a, int b, int c) {
    int countA[10] = {0};
    int countB[10] = {0};
    int countC[10] = {0};

    while (a > 0) {
        countA[a % 10]++;
        a /= 10;
    }
    while (b > 0) {
        countB[b % 10]++;
        b /= 10;
    }
    while (c > 0) {
        countC[c % 10]++;
        c /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (countA[i] != countB[i] || countA[i] != countC[i])
            return false;
    }
    return true;
}
