#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int count(int sum);

int coins[8] = {1,2,5,10,20,50,100,200};
int main(void) {

    printf("%d",count(200));

    return 0;
}


int count(int sum) {
    int max = sizeof(coins)/ sizeof(coins[0]);

    int dp[max+1][sum+1];
    for(int i = 0; i< max;i++) {
        for(int j = 0; j< sum;j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= max;i++) {
        for(int j =0;j <= sum;j++) {
            dp[i][j] = dp[i-1][j];
            if(j-coins[i-1]>= 0) {
                dp[i][j] = dp[i][j] + dp[i][j-coins[i-1]];
            }

        }
    }
    return dp[max][sum];
}