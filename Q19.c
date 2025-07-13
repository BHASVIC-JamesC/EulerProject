#include <stdio.h>

int main(void) {


    int dow = 3;
    int count = 0;
    // 30 day months : 9 4 6 11
    //31 day months :1 3 5 7 8 10 12
    // 28 or 29 days : 2
    // leap year divisible by 4


        int days_in_month[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            for (int x= 1901;x<=2000;x++) {
                for(int i = 0;i<12;i++) {
                    int days = 0;
                    int day = 1;
                    if(i == 1 && x % 4 == 0) {
                        days = 29;
                    }
                    else {
                        days = days_in_month[i];
                    }
                    while(day<=days) {
                        if(day == 1 && day == dow) {
                            count++;
                        }
                        day++;
                        if(dow != 7) {
                            dow++;
                        }
                        else {
                            dow = 1;
                        }
                        if(day == 1 && day == dow) {
                            count++;
                        }
                    }
                }

    }
    printf("%d",count);
    return 0;
}
