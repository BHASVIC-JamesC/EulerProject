#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
void sieve(int n);
bool inPrimeList(int n);

int primes[78498] = {0};
int main(void) {
    int sum = 0;
    int truncatable[11] = {0};
    int pointer = 0;
    sieve(1000000);



    for(int i = 0;i<78498;i++) {
        int number = primes[i];
        int ognumber = number;
        bool state = true;
        while(number> 10) {
            number=number/10;
            if(inPrimeList(number) == false) {
                state = false;
                break;
            }
        }
        if(state == true) {
            bool newstate = true;
            int num = ognumber;
            while(num>10) {
                int temp = num;
                int divisor = 1;
                while(temp>=10) {
                    temp /=10;
                    divisor *= 10;
                }
                num = num % divisor;
                if(inPrimeList(num) == false) {
                    newstate = false;
                }

            }if(newstate && ognumber > 10){
                //truncatable[pointer] = ognumber;
                printf("%d\n",ognumber);
                sum += ognumber;
                //pointer++;}
            }
        }
    }

    printf("\nsum:%d",sum);
    return 0;
    }



void sieve(int n) {
    int counter = 0;
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
            primes[counter] = j;
            counter ++;
        }
    }

}

bool inPrimeList(int n) {
    for(int i = 0;i<78498;i++) {
        if(n == primes[i]) {
            return true;
        }
    }
    return false;
}