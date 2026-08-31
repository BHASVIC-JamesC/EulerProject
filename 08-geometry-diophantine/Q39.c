#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int squares[1000];
void squaresList();


void merge(int list[],int mid,int left,int right) {
    int i,j,k;
    int n1 = mid-left+1;
    int n2 = right-mid;
    int leftList[n1];
    int rightList[n2];

    for(i =0;i<n1;i++) {
        leftList[i] = list[left + i];
    }
    for(j = 0;j<n2;j++) {
        rightList[j] = list[mid+j+1];
    }
    i=0;
    j=0;
    k=left;
    while(i < n1 && j < n2) {
        if(leftList[i] <= rightList[j]) {
            list[k] = leftList[i];
            i++;
        }
        else if(rightList[j] < leftList[i]) {
            list[k] = rightList[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        list[k] = leftList[i];
        i++;
        k++;
    }
    while(j<n2) {
        list[k] = rightList[j];
        j++;
        k++;
    }
}

void mergeSort(int list[],int left,int right) {

    if(left<right) {
        int mid = left + (right-left)/2;
        mergeSort(list,left,mid);
        mergeSort(list,mid+1,right);

        merge(list,mid,left,right);
    }
}

int main(void) {

    squaresList();
    int perimeters[1050] ={0};
    int pointer = 0;
    int a=1,b=1;
    double c;

    for(a = 3;a<500;a++) {
        for(b=3;b<500;b++) {
            c = a*a + b*b;
            for(int i =0;i<1000;i++) {
                if(squares[i] == c) {
                    int perimeter = a+b+squares[i-1];
                    if(perimeter < 1000) {
                        perimeters[pointer] = perimeter;
                        pointer++;
                    }
                    break;
                }
            }
        }
    }


    int size = sizeof(perimeters)/sizeof(perimeters[0]);
    mergeSort(perimeters,0,size -1);

    //for(int i =0;i<1000;i++) {
        //printf("\n%d",perimeters[i]);
   // }

    int maxfreq = 0;
    int maxPer = 0;
    int freq = 1;
    for(int i = 0;i<1049;i++) {

        if(perimeters[i+1] == perimeters[i] && perimeters[i] != 0) {
            freq++;
        }
        else {
            if(freq>maxfreq && perimeters[i] < 1000) {
                maxfreq = freq;
                maxPer = perimeters[i];
                freq = 1;
            }
            else {
                freq = 1;
            }
        }
    }
    printf("perimeter: %d  count:%d",maxPer,maxfreq);

    return 0;
}

void squaresList() {
    int pointer = 0;
    int placement = 3;
    while(placement <= 1003) {
        squares[pointer] = placement;
        pointer++;
        squares[pointer] = placement*placement;
        placement++;
        pointer ++;
    }
}