#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    setbuf(stdout, 0);
    int first =990,second=100;
    for(int i =first ;i<=999;i++) {
        for(int j =second;j <=999;j++) {
            int product = i*j;
            char integer[7];
            char reverse[7];
            sprintf(integer,"%d",product);
            fflush(stdin);
            sprintf(reverse,"%d",product);
            fflush(stdin);
            strcpy(reverse,strrev(reverse));
            int answer = strcmp(reverse,integer);
            if(answer ==0) {
                puts(integer);
            }
        }
    }


    return 0;
}
