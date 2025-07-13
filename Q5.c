#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int value=0,x=100,n=0;

    while(value==0) {
        n=0;
        for(int k = 1;k<21;k++) {
            if(x%k==0) {
                n++;
            }
        }
        if(n==20) {
            value = 1;
            printf("%d",x);
        }
        x++;
    }

    return 0;
}