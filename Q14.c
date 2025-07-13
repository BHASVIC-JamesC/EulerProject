#include <stdio.h>
#include <math.h>

int collatz(unsigned long long int n,int total);

int main(void) {
    int high = 0,number;
    for(int i = 1;i<1000000;i++) {
        int ans = collatz(i,0);
        if (ans>high) {
            high = ans;
            number = i;}
    }
    printf("%llu has %d terms ",number,high);
}

int collatz(unsigned long long int n,int total) {
    if(n==1) {
        total++;
        return total;
    }
    if(n%2==0) {
    total ++;
        return collatz(n/2,total);
    }
    if(n%2==1) {
        total ++;
        return collatz((3*n)+1,total);
    }
}