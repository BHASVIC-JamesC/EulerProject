#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main(void) {

    int total =0;
    for(int x = 1;x<20;x++) {
        for(int y = 1;y<10000000;y++) {
            float ans = floor(y * log10(x))+1;
            if(y == ans) {
                printf("%d ** %d\n",x,y);
                total ++;

            }
        }
    }
   printf("\ntotal:%d",total);



    return 0;
}