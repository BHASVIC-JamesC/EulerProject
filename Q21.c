#include <stdio.h>
#include <math.h>
int dividors (int x);
int main(void) {
    int rtotal = 0;
    int amicable[10000] ={0};
    int i =0;
    for(int x = 1;x<10000;x++) {
        int num = dividors(x);
        if(dividors(num) == x && num != x) {
            int allowed = 0,allowed1=0;
            for(int p = 0;p<10000;p++) {
                if(amicable[p] == x) {
                    allowed = 0;
                    break;
                }
                else {
                    allowed = 1;
                }
            }
            for(int p =0;p<10000;p++) {
                if(amicable[p] == num) {
                    allowed1 = 0;
                    break;
                }
                else {
                    allowed1=1;
                }
            }

            if(allowed == 1) {
                rtotal = rtotal + x;
            }
            if(allowed1 == 1) {
                rtotal = rtotal + num;
            }
            amicable[i] = x;
            amicable[i+1] = num;
            i = i+2;
        }
    }
    printf("%d",rtotal);
    return 0;
}

int dividors(int x) {
    int total = -x;

    int i =1;
    while(i< sqrt(x)) {
        if(x % i == 0) {
            total = total + i;
            total = total + x/i;
        }
        i++;
    }
    return total;
}