#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

bool binaryConvertor(int num);

bool palindromicBinary(int* arr,int size);

int main(void) {
    int sum = 0;
    for(int i = 1;i<=1000000;i++) {
        int original = i,reversed=0,remainder;
        while(original != 0) {
            remainder = original%10;
            reversed = reversed * 10 + remainder;
            original = original/10;
        }
        if(binaryConvertor(i) == true && i == reversed) {
            printf("\n%d",i);
            sum = sum + i;
        }
    }

    printf("\nsum:%d",sum);
    return 0;
}

bool binaryConvertor(int num) {
    int count = 1;
    int tempnum  = num;
    while(tempnum/2 != 0){
        count++;
        tempnum = tempnum/2;

    }

    int binary[count];
    int place = count-1;
    int y = 0;
    do {
        y = num % 2;
        num = num/2;
        binary[place] = y;
        place--;
    }
    while(num != 0);

    return palindromicBinary(binary,count);
}

bool palindromicBinary(int* arr,int size) {

    int reverseArr[size];
    int end = size-1;
    for(int i = 0;i< size;i++) {
        reverseArr[i] = arr[end];
        end--;
    }

    //for(int i = 0;i<size;i++) {
        //printf("%d",reverseArr[i]);
    //}
    //printf("\n");
    //for(int i = 0;i<size;i++) {
    //    printf("%d",arr[i]);
    //}
    bool state = true;
    if(reverseArr[0] == 0){
        state = false;}
    for(int i = 0 ;i < size;i++) {

        if(reverseArr[i] != arr[i]) {
            state = false;
        }
    }
    return state;

}