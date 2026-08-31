#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// first index i such that arr[i] >= val
int lower_bound(long long *arr, int n, long long val) {
    int lo = 0, hi = n; // [lo, hi)
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= val) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// first index i such that arr[i] > val
int upper_bound(long long *arr, int n, long long val) {
    int lo = 0, hi = n; // [lo, hi)
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > val) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(void) {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int N, Q;
    scanf("%d %d", &N, &Q);

    static long long x[100000];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[i]);
    }

    // sort positions
    qsort(x, N, sizeof(long long), compare);

    // answer queries
    for (int i = 0; i < Q; i++) {
        long long A, B;
        scanf("%lld %lld", &A, &B);

        int L = lower_bound(x, N, A); // >= A
        int R = upper_bound(x, N, B); // > B
        printf("%d\n", R - L);
    }

    return 0;
}
