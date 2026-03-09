#include <stdio.h>
#include <stdbool.h>

int main(void) {
    unsigned long long int start = 316227760;
    bool state = false;
    while(!state) {
        unsigned long long x = start*start;

        // Check if last digit is 0
        if (x % 10 != 0) {
            start+=10;
            continue;
        }

        unsigned long long int temp = x;
        int count = 9;
        bool valid = true;
        temp/=10;
        // Check every second digit from the right
        while (count >= 1) {
            temp /= 10; // skip one digit
            unsigned long long int digit = temp % 10;
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
            start+=10;
        }
    }

    printf("start: %llu\n",start);
    return 0;
}
