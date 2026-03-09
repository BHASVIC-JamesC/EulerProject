#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

typedef long long ll;

//Fenwick tree

int n;
ll fenwick[MAXN];

void update(int i, ll delta) {
    while (i <= n) {
        fenwick[i] += delta;
        i += i & -i;
    }
}

ll query(int i) {
    ll sum = 0;
    while (i > 0) {
        sum += fenwick[i];
        i -= i & -i;
    }
    return sum;
}

ll range_sum(int l, int r) {
    return query(r) - query(l - 1);
}

//creating structures to value and index tree

typedef struct {
    ll value;
    int index;
} Pair;

int cmp_desc(const void *a, const void *b) {
    Pair *p1 = (Pair*)a;
    Pair *p2 = (Pair*)b;
    if (p1->value < p2->value) return 1;
    if (p1->value > p2->value) return -1;
    return p1->index - p2->index;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        Pair arr[MAXN];

        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i].value);
            arr[i].index = i + 1;   // 1-indexed for Fenwick
        }

        // Reset Fenwick
        for (int i = 1; i <= n; i++)
            fenwick[i] = 0;

        // Mark all positions alive
        for (int i = 1; i <= n; i++)
            update(i, 1);

        // Sort by value descending
        qsort(arr, n, sizeof(Pair), cmp_desc);

        ll swaps = 0;

        int left_alive = 1;
        int right_alive = n;

        int i = 0;

        while (i < n) {
            ll current_value = arr[i].value;

            int start = i;
            while (i < n && arr[i].value == current_value)
                i++;
            int end = i - 1;

            int l = start;
            int r = end;

            while (l <= r) {
                int lpos = arr[l].index;
                int rpos = arr[r].index;

                ll cost_l_left  = range_sum(left_alive, lpos) - 1;
                ll cost_l_right = range_sum(lpos, right_alive) - 1;
                ll cost_r_left  = range_sum(left_alive, rpos) - 1;
                ll cost_r_right = range_sum(rpos, right_alive) - 1;

                ll best = cost_l_left;
                if (cost_l_right < best) best = cost_l_right;
                if (cost_r_left < best) best = cost_r_left;
                if (cost_r_right < best) best = cost_r_right;

                swaps += best;

                if (best == cost_l_left || best == cost_l_right) {
                    update(lpos, -1);
                    l++;
                } else {
                    update(rpos, -1);
                    r--;
                }
            }
        }

        printf("%lld\n", swaps);
    }

    return 0;
}
