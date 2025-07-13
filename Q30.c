#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(void) {
    int total = 0;
    for(int i = 10; i<100;i++) {
        int digit2 = i%10;
        int digit1 = i/10;
        double x = i;
        if((pow(digit1,5) + pow(digit2,5)) == x) {
            printf("%d\n",i);
            total = total + i;
        }
    }

    for(int i = 100; i<1000;i++) {
        int digit1 = i/100;
        int digit2 = (i/10) % 10;
        int digit3 = i % 10;
        double x = i;
        if((pow(digit1,5) + pow(digit2,5) + pow(digit3,5)) == x) {
            printf("%d\n",i);
            total = total + i;
        }
    }

    for(int i = 1000; i < 10000;i++) {
        int digit1 = i/1000;
        int digit2 = (i/100)% 10;
        int digit3 = (i/10) % 10;
        int digit4 = i%10;

        double x = i;
        double result = pow(digit1,5) + pow(digit2,5) + pow(digit3,5) + pow(digit4,5);
        if((result) == x) {
            printf("%d\n",i);
            total = total + i;

        }

    }

    for(int i = 10000; i < 100000;i++) {
        int digit1 = i/10000;
        int digit2 = (i/1000)% 10;
        int digit3 = (i/100) % 10;
        int digit4 = (i/10) % 10;
        int digit5 = i%10;


        double x = i;
        if((pow(digit1,5) + pow(digit2,5) + pow(digit3,5) + pow(digit4,5) + pow(digit5,5)) == x) {
            printf("%d\n",i);
            total = total + i;
        }
    }

    for(int i = 100000; i < 1000000;i++) {
        int digit1 = i/100000;
        int digit2 = (i/10000)% 10;
        int digit3 = (i/1000) % 10;
        int digit4 = (i/100) % 10;
        int digit5 = i/10 % 10;
        int digit6 = i%10;


        double x = i;
        if((pow(digit1,5) + pow(digit2,5) + pow(digit3,5) + pow(digit4,5) + pow(digit5,5) + pow(digit6,5)) == x) {
            printf("%d\n",i);
            total = total + i;
        }
    }



    printf("total:%d",total);

    return 0;
}