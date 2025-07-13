#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

bool primeChecker(int n);

int main(void) {
    int max = 0;
    int maxa,maxb;
    for(int a = -999;a<1000;a++) {
        for(int b = -1000;b<=1000;b++) {
            int run = true;
            int start = 0;
            while(run == true) {
                int ans = start*start + a*start + b;
                if(primeChecker(ans) == true) {
                    start++;
                }
                else {
                    run = false;
                }

            }
            if(start > max) {
                max = start;
                maxa = a;
                maxb = b;
            }

        }
    }

    printf("the number of consececutive primes was:%d\na:%d   b:%d\nthe product of the 2 is %d",max,maxa,maxb,maxa*maxb);

    return 0;
}

bool primeChecker(int n) {
    if(n>0) {
        for(int i = 2;i<= sqrt(n);i++) {
            if(n%i==0) {
                return false;
            }
        }
    }
    else {
        for(int i = 2;i<= sqrt(-n);i++) {
            if(n%i==0) {
                return false;
            }
        }
    }

    return true;
}