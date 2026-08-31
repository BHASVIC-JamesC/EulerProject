#include <stdio.h>
#include <stdlib.h>

#define SIZE 80

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    FILE *file = fopen("C:\\Users\\james\\Downloads\\comp sci work\\eulerproject\\Q81", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    int matrix[SIZE][SIZE];

    // Reading the matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (fscanf(file, "%d,", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error reading data at (%d,%d)\n", i, j);
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);

    // Modify matrix in-place to store the minimal path sums
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0 && j == 0) continue; // top-left cell
            else if (i == 0)
                matrix[i][j] += matrix[i][j - 1]; // top row
            else if (j == 0)
                matrix[i][j] += matrix[i - 1][j]; // left column
            else
                matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }

    printf("Minimum path sum: %d\n", matrix[SIZE - 1][SIZE - 1]);
    return 0;
}
