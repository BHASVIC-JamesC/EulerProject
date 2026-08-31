#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

bool binarysearch(int* arr,int start,int end, int target);

int main(void){
    int pentagonal[10000] = {0};
    for(int i = 1;i<=10000;i++) {
        pentagonal[i-1] = i*(3*i-1)/2;
    }

    int diff = 1;
    int mindiff = 1000000000;
    while(diff<9999){
        for(int i = 0;i<=10000-diff;i++) {
            int difference = pentagonal[i+diff] - pentagonal[i];
            if(binarysearch(pentagonal,0,10000,difference) == true) {
                int sum = pentagonal[i] + pentagonal[i+diff];
                if(binarysearch(pentagonal,0,10000,sum) == true && difference< mindiff){
                    mindiff = difference;
                }
            }
        }
        diff++;
    }
    printf("minimum diff:%d",mindiff);
  return 0;}


bool binarysearch(int* arr,int start,int end,int target) {
    if(end<=start || end-start == 1) {
        return false;
    }
    int mid = (start + end)/2;


    if(arr[mid] == target) {
        return true;
    }
    else if(arr[mid] > target) {
        end = mid;
        return binarysearch(arr,start,end,target);
    }
    else{
        start = mid;
        return binarysearch(arr,start,end,target);
    }
}