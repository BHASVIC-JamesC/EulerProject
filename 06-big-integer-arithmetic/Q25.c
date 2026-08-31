#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

void findLargeFibonacci() {
    int first[MAX_DIGITS] = {0}, second[MAX_DIGITS] = {0}, result[MAX_DIGITS] = {0};
    first[MAX_DIGITS - 1] = 1;
    second[MAX_DIGITS - 1] = 1;

    int index = 3;

    while (1) {

        int carry = 0;
        for (int i = MAX_DIGITS - 1; i >= 0; i--) {
            int sum = first[i] + second[i] + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }

        // Check if we reached 1000 digits
        if (result[0] != 0) {
            printf("Index of first 1000-digit Fibonacci number: %d\n", index);
            break;
        }


        memcpy(first, second, sizeof(first));
        memcpy(second, result, sizeof(second));

        index++;
    }


    printf("1000-digit Fibonacci number: \n");
    for (int i = 0; i < MAX_DIGITS; i++) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    findLargeFibonacci();
    return 0;
}
