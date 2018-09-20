#include <bits/stdc++.h>

using namespace std;

int segment_tree(int a[], int tree[], int lo, int hi, int i)
{
    if (lo == hi) {
        tree[i] = a[lo];
        return a[lo];
    }

    int mid = (lo+hi) / 2;
    tree[i] = segment_tree(a, tree, lo, mid, 2*i+1) + segment_tree(a, tree, mid+1, hi, 2*i+2);

    return tree[i];
}

int sum_query(int tree[], int lo, int hi, int l, int r, int i)
{
    if (hi < l || lo > r) return 0;
    if (lo >= l && hi <= r) return tree[i];

    int mid = (lo+hi) / 2;
    return sum_query(tree, lo, mid, l, r, 2*i+1) + sum_query(tree, mid+1, hi, l, r, 2*i+2);
}

int main()
{
    int n, q, l, r, sum;

    scanf("%d", &n);
    int a[n], tree[2*n+1];

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    segment_tree(a, tree, 0, n-1, 0);
    scanf("%d", &q);

    while (q--) {
        scanf("%d%d", &l, &r);
        sum = sum_query(tree, 0, n-1, l, r, 0);
        printf("%d\n", sum);
    }

    return 0;
}
