#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void sieve(int n);



int main(void) {
    sieve(100000000);
    return 0;
}


void sieve(int n) {

    bool* prime = malloc((n + 1) * sizeof(bool));
    if (!prime) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i <= n; i++) prime[i] = true;

    for(int x = 2;x*x<=n;x++) {

        if(prime[x] == true) {
            for(int p = x*x ;p<= n;p += x) {
                prime[p] = false;
            }
        }
    }

    for(int j =2; j<= n;j ++) {
        if(prime[j]== true) {
            int digitCount = 0;
            bool digits[10] = {false};
            int num = j;
            bool unique = true;
            while(num > 0){
                int digit = num % 10;
                if(digit == 0 || digit == 8 || digit == 9) {
                    unique = false;
                    break;
                }
                num/=10;
                if(digits[digit]) {
                    unique = false;
                    break;
                }
                digits[digit] = true;
                digitCount++;
            }
            if(unique && digitCount == 7) {
                printf("%d\n",j);
            }
        }
    }
    free(prime);
}
