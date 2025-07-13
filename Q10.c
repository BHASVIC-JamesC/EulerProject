#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void sieve(int n,int unsigned long long sum);

int main(void) {
    setbuf(stdout,NULL);
    int number = 2000000;

    sieve(number,0);
}

void sieve(int n,unsigned long long int sum) {

    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for(int x = 2;x*x<=n;x++) {

    if(prime[x] == true) {
        for(int p = x*x ;p<= n;p += x) {
            prime[p] = false;
        }
    }
    }

    for(int j =2; j<= n;j ++) {
        if(prime[j]== true) {
            sum += j;
        }
    }
    printf("%llu",sum);
}