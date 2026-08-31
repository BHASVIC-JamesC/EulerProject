#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int minimum = 1000000;//track the minimum
int minArea = 0;

int main(void) {
    for (int n = 0;n<100;n++) {
        for (int m = n;m<100;m++) {
            int diff = abs(2000000 - n*(n+1)/2 * m*(m+1)/2);
            if( minimum > diff) {
                minimum = diff;
                minArea = n*m;
            }
        }
    }

    printf("minimum Area:%d",minArea);
}


