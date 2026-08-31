#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

bool makeKPairs(ll D, int k, int N, ll *pos, ll C) {
    if (D > C / 2) return false; // no circular distance can be >= D

    for (int start = 0; start < N; start++) {
        int end = start + N;
        int mid = start + N / 2;

        int count = 0;
        int i = start;
        int j = mid;

        while (i < mid && j < end) {
            ll gap = pos[j] - pos[i];
            if (gap >= D && gap <= C - D) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }

            if (count >= k) return true;
        }
    }
    return false;
}

int main(void) {
    int N;
    ll C;
    if (scanf("%d %lld", &N, &C) != 2) return 0;

    ll *positions = malloc(sizeof(ll) * 2 * N);
    if (!positions) return 0;

    for (int i = 0; i < N; i++) {
        if (scanf("%lld", &positions[i]) != 1) {
            free(positions);
            return 0;
        }
    }

    // duplicate for circle
    for (int i = 0; i < N; i++) {
        positions[i + N] = positions[i] + C;
    }

    int maxK = N / 2;

    for (int k = 1; k <= maxK; k++) {
        ll low = 0;
        ll high = C / 2;
        ll answerk = 0;

        while (low <= high) {
            ll mid = (low + high) / 2;

            if (makeKPairs(mid, k, N, positions, C)) {
                answerk = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        printf("%lld", answerk);
        if (k < maxK) printf(" ");
    }

    printf("\n");

    free(positions);
    return 0;
}