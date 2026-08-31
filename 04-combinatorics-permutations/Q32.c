#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

bool set(int* ourdigit);

int main(void) {
    int total[10] = {0};
    int pointer = 0;
    int totalsum = 0;
    for(int a = 1;a<=9;a++) {
        for(int b = 1000;b<=9999;b++) {
            int c = a*b;
            if(c < 1000 || c>10000) continue;
            int digit1a = a%10;
            //int digit2a = a%10;
            int digit1b = b/1000;
            int digit2b = b/100 % 10;
            int digit3b = b /10 %10;
            int digit4b = b% 10;
            int digit1c = c/1000;
            int digit2c = c/100 %10;
            int digit3c = c/10 %10;
            int digit4c = c % 10;
            ;
            int ourdigit[9] = {digit1a,digit1b,digit2b,digit3b,digit4b,digit1c,digit2c,digit3c,digit4c};
            if(set(ourdigit) == true) {
                bool pass = true;
                for(int i = 0;i<10;i++) {
                    if(c == total[i]) {
                        pass = false;
                    }
                }
                if(pass == true) {
                    total[pointer] = c;
                    printf("%d x %d = %d\n",a,b,total[pointer]);
                    pointer ++;
                    totalsum = totalsum + c;
                }

            }


        }
    }

    printf("total sum:%d",totalsum);
    return 0;
}

bool set(int* arr) {

    for(int i = 0;i<8;i++) {
        for(int j = i+1;j<9;j++) {

            if(arr[i] == arr[j] || arr[i] == 0 || arr[j] == 0) {
                return false;

            }
        }
    }

    return true;


}

