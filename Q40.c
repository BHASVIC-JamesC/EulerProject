
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int *arr = (int*)malloc(1000000 * sizeof(int));  // Use dynamic memory
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    int start = 1;
    int pointer = 0;
    while(pointer<1000000) {
        int number = start;


        int temp = start;
        int check = temp;
        int count = 0;
        while(check>0) {
            check/=10;
            count++;
        }
        int digits[count];
        int pointer2 = 0;
        while(temp > 0) {
            digits[pointer2++] = temp % 10;
            temp/=10;
        }

        for(int i = count-1;i>=0 && pointer< 1000000;i--) {
            arr[pointer++] = digits[i];
        }

        start++;
    }


    printf("%d",arr[9] * arr[99] * arr[999] * arr[9999] * arr[99999]);

    free(arr);
    return 0;
}
