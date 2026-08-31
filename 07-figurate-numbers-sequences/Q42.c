#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void triangular();
int triangles[100] = {0};
int main(void) {

    int count = 0;
    triangular(triangles);
    FILE *file;
    file = fopen("C:\\Users\\james\\Downloads\\comp sci work\\eulerproject\\Q42", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char words[16345] = "";
    fgets(words,16345,file);
    char* Words = strtok(words,",");
    char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(Words != NULL) {

        int length = strlen(Words);
        //printf("%s  %d\n",Words,length);
        int sum = 0;
        for(int i = 1; i< length-1;i++) {
            int letter = 0;
            for(int x = 0;x<25;x++) {
                if(Words[i] == letters[x]) {
                     letter = x+1;
                     break;
                }
            }
            if(Words[i] != '"') {
                sum = sum + letter;
            }
        }
        for(int x = 0;x<100;x++) {
            if(triangles[x] == sum) {
                printf("\n%s  %d\n",Words,sum);
                count++;
                break;
                }
        }
        Words = strtok(NULL,",");
    }/*
    int sum2 = 0;
    char etc[] = {"AZURE"};
    int length = sizeof(etc)-1;
    for(int i = 0; i< length;i++) {
        int letter = etc[i] - 64;
        printf("%d ",letter);
        sum2+=letter;
    }
    printf("\n%d\n",sum2);
    for(int i = 0;i<30;i++) {
        printf("%d ",triangles[i]);
    }*/
    fclose(file);
    printf("\ncount:%d",count);
    return 0;
}

void triangular() {
    int initial = 1;
    int pointer = 0;
    while(pointer<100) {
        triangles[pointer++] = (initial*(initial+1))/2;
        initial++;
    }
}