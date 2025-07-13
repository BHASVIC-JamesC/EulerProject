#include <stdio.h>

int main(void) {
    int total = 0;
    int running =0;
    while(running<1000) {
        if(running %5==0 || running % 3 == 0) {
            total =total+running;}
        running ++;
    }
    printf("%d",total);
    return 0;
}
