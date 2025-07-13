#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


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
int binarySearch(int list[],int target,int low,int high) {
    while(low<=high) {
        int middle = (low + high)/2;
        int newList[middle];
        if(list[middle] == target) {
            return 1;
        }
        else if(list[middle]< target) {
            low = middle +1;
        }
        else {
            high = middle -1;
        }
        return binarySearch(list,target, low, high);
    }
    return 0;
}
int main(void) {

    int list[] = {12,42,34213,43,5342,634,454,353,3,53,6,3,6,4,3,56435,35343,534,4,53,76,75,756,43,53,24,23,22,52,422,134,124,643,52};

    int size = sizeof(list)/sizeof(list[0]);
    mergeSort(list,0,size -1);


    int size2 = sizeof(list)/sizeof(list[0]);
    int high = size2 - 1;
    int number;
    printf("what number would you like to search for?:");
    fflush(stdin);
    scanf("%d",&number);
    if(binarySearch(list,number,0,high) == 1) {
        printf("\nthe target is in the list!");
    }
    else {
        printf("\ntarget not found.");
    }
    return 0;
}
