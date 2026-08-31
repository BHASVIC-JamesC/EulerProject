#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int sumSquared,squareSum;
    for(int i=1;i<101;i++) {
        squareSum = squareSum + (i*i);
        sumSquared += i;
    }
    int difference = (sumSquared*sumSquared)-squareSum;
    printf("%d",difference);
    return 0;
}