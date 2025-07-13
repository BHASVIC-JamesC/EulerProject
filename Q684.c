#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long long int S(unsigned long long int num);
unsigned long long int s(unsigned long long int num);

int main(void) {
    unsigned long long int fibonacci[91] = {0};
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int x = 2; x < 91; x++) {
        fibonacci[x] = fibonacci[x - 1] + fibonacci[x - 2];
    }

    unsigned long long int Total = 0;
    for(int x = 2; x <= 90; x++) {
        Total += S(fibonacci[x]);
    }

    unsigned long long int answer = Total % 1000000007;
    printf("total: %llu\n", Total);
    printf("answer: %llu\n", answer);
    return 0;
}

unsigned long long int S(unsigned long long int num) {
    unsigned long long int total = 0;
    for(unsigned long long int x = 1; x <= num; x++) {
        total += s(x);
    }
    return total;
}

unsigned long long int s(unsigned long long int num) {
    unsigned long long int x = 0;
    unsigned long long int digitsum = 0;
    while(digitsum != num) {
        x++;
        digitsum = 0;
        unsigned long long int temp = x;
        while(temp > 0) {
            int digit = temp % 10;
            digitsum += digit;
            temp /= 10;
        }
    }
    return x;
}
