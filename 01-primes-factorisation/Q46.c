#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


void SieveOfEratosthenes(int n,long long int* composites,long long int* Primes);





int main(void) {
    long long int* primes = malloc(10000 * sizeof(long long int));
    long long int* Composites = malloc(10000 * sizeof(long long int));
    long long int* doubleSquares = malloc(10000 * sizeof(long long int));



    for(int i = 1;i<=10000;i++) {
        doubleSquares[i-1] =(long long int) 2*(i*i);
    }

    SieveOfEratosthenes(104730,Composites,primes);


    /*for(int i = 0;i<1000;i++) {
        printf("%d ",primes[i]);
    }
    printf("\n\n\n\n\n");
    for(int i = 0;i<1000;i++) {
        printf("%d ",doubleSquares[i]);
    }*/
    for(int i =0;i<10000;i++) {
        long long int target = Composites[i];
        int start = 0, end = 9999;
        bool found = false;
        while(start<end) {
            if(primes[start]+doubleSquares[end] == target) {
                found = true;
                //printf("%d + %d = %d",primes[start],doubleSquares[end],target);
                break;
            }
            else if(primes[start]+doubleSquares[end] < target) {
                start++;
            }
            else if(primes[start]+doubleSquares[end] > target) {
                end--;
            }
        }
        if(found == false) {
            int nstart = 0,nend = 9999;
            while(nstart<nend) {
                if(primes[nend]+doubleSquares[nstart] == target) {
                    found = true;
                    //printf("%d + %d = %d",primes[nend],doubleSquares[nstart],target);
                    break;
                }
                else if(primes[nend]+doubleSquares[nstart] < target) {
                    nstart++;
                }
                else if(primes[nend]+doubleSquares[nstart] > target) {
                    nend--;
                }
            }
        }
        if(found == false) {
            printf("i found it: %lld",target);
        }
    }
    free(primes);
    free(doubleSquares);
    free(Composites);
    return 0;
}



void SieveOfEratosthenes(int n,long long int* composites,long long int* Primes)
{

    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    long long int count = 0,otherCount = 0;

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers

    for (int p = 2; p <= n; p++) {
        if (prime[p] == true) {
            Primes[count] = (long long int)p;
            count++;

        }
        if(otherCount<10000) {
            if(p%2 == 1 && prime[p] == false) {
                composites[otherCount] = (long long int) p;
                otherCount++;
            }
        }
    }


}

