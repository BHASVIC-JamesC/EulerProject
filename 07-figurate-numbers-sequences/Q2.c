#include <stdio.h>
#include <math.h>

int main(void) {
    setbuf(stdout, 0);
    int fibonacci[33] = {1,1,2,3};
    int i;
    int n =33;
    int total = 2;
    for(i=4;i<n;i++){
        fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
        if(fibonacci[i]%2==0) {
            total=total+fibonacci[i];
        }
    }
    printf("%d",total);



    return 0;
}