#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    FILE *file = fopen("C:\\Users\\james\\Downloads\\comp sci work\\eulerproject\\Q67", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int arr[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            fscanf(file, "%d", &arr[i][j]);
        }
    }
    fclose(file);

    for (int i = 98; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
        }
    }

    printf("Maximum total: %d\n", arr[0][0]);
    return 0;
}
