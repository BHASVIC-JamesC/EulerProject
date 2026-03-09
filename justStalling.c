#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    long long a[20], b[20];

    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%lld", &b[i]);
    }



    return 0;
}
