#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    long long int sum = 0;
    long long int Num = 1;

    while(Num<=100000000) {
        Num ++;
        long long  int num = Num*Num;
        long long int length = 0;
        long long  int temp = num;
        while(temp>0) {
            temp/=10;
            length++;
        }


        long long int num1 =0,num2 = 0;
        temp = num;
        int digits[length];
        for(int digit = length-1;digit>=0;digit--) {
            digits[digit] = temp%10;
            temp/=10;}
        if(digits[length/2] == 0) {

            continue;
        }

        for(int first = 0;first < length/2;first++) {
            num1 = num1 + digits[first];
            num1=num1*10;
        }
        num1/=10;
        for(int second = length/2;second < length;second++) {
            num2 = num2 + digits[second];
            num2=num2 * 10;
        }
        num2/=10;
        if((num1 + num2)*(num1+num2) == num) {
            printf("%lld\n",num);
            sum = sum + num;
        }
    }

    printf("sum:%lld",sum);
    return 0;
}