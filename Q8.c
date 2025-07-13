#include <stdio.h>
#include <stdbool.h>

int main(void) {
    FILE *file;
    char c;
    unsigned long long int high = 0;  // Changed to unsigned long long int

    // Open the file in read mode
    file = fopen("C:\\Users\\james\\Downloads\\comp sci work\\eulerproject\\Q8", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Loop through all positions in the file
    for (int j = 0; j < 1000; j++) {
        fseek(file, j, SEEK_SET);  // Move to the j-th position
        unsigned long long int product = 1;  // Changed to unsigned long long int
        bool valid = true;

        // Calculate product of 13 digits
        for (int i = 0; i < 13; i++) {
            c = fgetc(file);

            if (c == EOF) {
                valid = false;
                break;
            }

            int x = c - '0';  // Convert char to int
            if (x < 0 || x > 9) {
                valid = false;  // Invalid digit, skip this sequence
                break;
            }

            product *= x;
        }

        // If the product is valid and larger than the previous highest, update
        if (valid && product > high) {
            high = product;
        }
    }

    fclose(file);
    printf("Highest product: %llu\n", high);  // Use %llu for unsigned long long int

    return 0;
}
