#include <stdio.h>
#include <stdbool.h>


int main(void) {
    int a,b,c;

    for(int i =5;i<500;i++) {
    a = i;
        for(int j = 4;j<500;j++) {
            b=j;
            for(int x =3;x<500;x++) {
                c=x;
                if(((a*a)+(b*b) == c*c) && a+b+c == 1000) {
                    printf("found it!\n%d",a*b*c);
                }
            }}


    }

    return 0;
}