#include <stdio.h>

#include <stdbool.h>


int main(void){
int total = 0;
for(int i = 1;i<10000000;i++) {
    int num = i;
    bool run = true;
    int newNum = 0;
    while(run){
        while(num>0) {
            int digit = num % 10;
            num /=10;
            newNum += digit*digit;
        }
        if(newNum == 1) {
            break;
        }
        if(newNum == 89) {
            total++;
            break;
        }
        num = newNum;
        newNum = 0;

    }

}
    printf("%d",total);

  return 0;}