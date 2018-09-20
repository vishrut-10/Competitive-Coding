#include <bits/stdc++.h>

using namespace std;

int segment_tree(int a[], int tree[], int lo, int hi, int i)
{
    if (lo == hi) {
        tree[i] = a[lo];
        return a[lo];
    }

    int mid = (lo+hi) / 2;
    tree[i] = min(segment_tree(a, tree, lo, mid, 2*i+1),
                  segment_tree(a, tree, mid+1, hi, 2*i+2));

    return tree[i];
}

void update_range_query(int tree[], int lazy[], int l, int r, int d, int lo, int hi, int i)
{
    if (lo > hi) return;

    if (lazy[i] != 0) {
        tree[i] += lazy[i];

        if (lo != hi) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (lo > r || hi < l) return;

    if (lo >= l && hi <= r) {
        tree[i] += d;

        if (lo != hi) {
            lazy[2*i+1] += d;
            lazy[2*i+2] += d;
        }

        return;
    }

    int mid = (lo+hi) / 2;
    update_range_query(tree, lazy, l, r, d, lo, mid, 2*i+1);
    update_range_query(tree, lazy, l, r, d, mid+1, hi, 2*i+2);

    tree[i] = min(tree[2*i+1], tree[2*i+2]);
}


int min_query(int tree[], int lazy[], int lo, int hi, int l, int r, int i)
{
    if (lo > hi) return INT_MAX;

    if (lazy[i] != 0) {
        tree[i] += lazy[i];

        if (lo != hi) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (lo > r || hi < l) return INT_MAX;

    if (lo >= l && hi <= r) return tree[i];

    int mid = (lo+hi) / 2;
    return min(min_query(tree, lazy, lo, mid, l, r, 2*i+1),
               min_query(tree, lazy, mid+1, hi, l, r, 2*i+2));
}

int main()
{
    int n, q, x, l, r, d, ans;

    scanf("%d", &n);
    int a[n], tree[4*n], lazy[4*n];

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    segment_tree(a, tree, 0, n-1, 0);

    for (int i = 0; i < 4*n; i++) lazy[i] = 0;
    scanf("%d", &q);

    while (q--) {
        scanf("%d", &x);

        if (x == 1) {
            scanf("%d%d%d", &l, &r, &d);
            update_range_query(tree, lazy, l, r, d, 0, n-1, 0);
        } else {
            scanf("%d%d", &l, &r);
            ans = min_query(tree, lazy, 0, n-1, l, r, 0);
            printf("%d\n", ans);
        }
    }

    return 0;
}
