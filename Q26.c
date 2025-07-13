#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int periodic(int* decimals);

int main(void) {
    int max = 0;
    int position = 0;
    for(int i = 2;i<=1000;i++) {
        int decimals[1000] = {0};
        int place = 0;
        int first = 10;
        int second = i;
        decimals[place] = first/second;
        place++;
        first = 10 * (first%second);
        int x = 0;
        while(x<999) {
            decimals[place] = first/second;
            first = 10 * (first % second);
            place++;
            x++;
        }
        printf("%d\n",periodic(decimals));

    }

    return 0;
}

int periodic(int* decimals) {
    int length = 0;
    int period[1000] = {0};
    period[0] = decimals[0];
    for(int i = 1;i<1000;i++) {
        if(decimals[i] != decimals[0]) {
            length ++;
            period[i] = decimals[i];
        }
        else {
            bool state = true;
            int start = 0;
            for(int x = i;x<=length;x++) {
                if(period[start] == decimals[x]) {
                    state = true;
                }
                else {
                    state = false;
                    return 0;

                }
            }
        }
    }
    return length;


}

