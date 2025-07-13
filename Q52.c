#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void addDigits(int n,int* array);

int main(void) {

    for(int i = 10;i<1000000;i++) {
        int array[10] = {0};
        int num = i;
        int num2 = 2*i;
        int num3 = 3*i;
        int num4 = 4*i;
        int num5 = 5*i;
        int num6 = 6*i;

        addDigits(num,array);
        addDigits(num2,array);
        addDigits(num3,array);
        addDigits(num4,array);
        addDigits(num5,array);
        addDigits(num6,array);
        int length = 0;
        int temp = num;
        int temparray[10] = {0};
        while(temp>0) {
            temparray[temp%10]=1;
            temp/=10;
        }
        int count = 0;
        for(int x=0;x<10;x++) {
            if(array[x] == 1) {
                count ++;
            }
            if(temparray[x] == 1) {
                length++;
            }
        }
        if(count == length) {
            printf("%d\n",i);
        }

    }

    return 0;
}

void addDigits(int n,int* array) {
    while(n>0) {
        int i = n%10;
        array[i] = 1;
        n/=10;
    }
}