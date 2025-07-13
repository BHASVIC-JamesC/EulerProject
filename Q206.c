#include <stdio.h>
#include <stdbool.h>

int main(void) {
    unsigned long long int x = 1111111111111111111;
    bool state = false;

    while(!state) {
        

        // Check if last digit is 0
        if (x % 10 != 0) {
            x += 10;
            continue;
        }

        unsigned long long int temp = x;
        int count = 9;
        bool valid = true;

        // Check every second digit from the right
        while (count >= 1) {
            temp /= 10; // skip one digit
            int digit = temp % 10;
            if (digit != count) {
                valid = false;
                break;
            }
            count--;
            temp /= 10; // move to next relevant digit
        }

        if (valid) {
            state = true;
        } else {
            x ++;
        }
    }

    printf("x: %llu\n", x);
    return 0;
}
