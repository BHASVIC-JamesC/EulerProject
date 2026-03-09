#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int reverse(unsigned long long int n);

bool palindromic(unsigned long long int n);

int main(void) {

    int total = 0;
    for(int x = 1;x<10000;x++) {
        unsigned long long int temp = x;
        bool state = false;
        temp = temp + reverse(temp);
        for(int y = 0;y<49;y++) {
            if(palindromic(temp)){
                state = true;
                break;
            }
            temp = temp + reverse(temp);

        }
        if(state == false) {
            total++;
            printf("%d\n",x);
        }

    }
    printf("%d",total);
    return 0;
}

int reverse(unsigned long long int n) {
    int reverse = 0;
    while(n>0) {
        reverse = reverse * 10 + n % 10;
        n/=10;
    }
    return reverse;
}

bool palindromic(unsigned long long int n) {
    if(n == reverse(n)) {
        return true;
    }
    return false;
}