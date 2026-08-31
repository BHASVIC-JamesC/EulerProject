#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(void) {
    int numerator = 1;
    int denominator = 1;
    for(int a = 10;a<100;a++) {
        for(int b = 10;b<100;b++) {
            double digit1a = a/10;
            double digit2a = a % 10;
            double digit1b = b/10;
            double digit2b = b%10;
            if(digit2a == 0 && digit2b == 0)continue;

            if(digit1b== digit2a && digit1a != digit2b && digit2b != 0 && digit1a != digit2a && digit1b != digit2b) {
                double tempa = a;
                double tempb = b;
                double ans = tempa/tempb;
                double fakeAns = digit1a/digit2b;
                if(ans == fakeAns && ans < 1 && fakeAns < 1) {
                    printf("%d/%d\n",a,b);
                    numerator *= a;
                    denominator *= b;
                }
            }

            if(digit1a == digit2b && digit2a != digit1b && digit2a != 0 && digit1a != digit2a && digit1b != digit2b) {
                double tempa = a;
                double tempb = b;
                double ans = tempa/tempb;
                double fakeAns = digit2a/digit1b;
                if(ans == fakeAns && ans < 1 && fakeAns < 1) {
                    printf("%d/%d\n",a,b);
                    numerator *= a;
                    denominator *= b;
                }
            }

        }
    }

    printf("numerator:%d\ndenominator:%d",numerator,denominator);

    return 0;
}