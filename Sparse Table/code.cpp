#include <bits/stdc++.h>

using namespace std;

int power(int x, int y)
{
    int res = 1;

    for (int i = 1; i <= y; i++) res *= x;

    return res;
}

int main()
{
    int n, q, lo, hi;

    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);

    int m = floor(log2(n)) + 1;
    int T[n][m];

    for (int i = 0; i < n; i++) T[i][0] = i;

    for (int j = 1; power(2, j) <= n; j++) {
        for (int i = 0; i + power(2, j) - 1 < n; i++) {
            if (a[T[i][j-1]] < a[T[i+ power(2, j-1)][j-1]]) {
                T[i][j] = T[i][j-1];
            } else {
                T[i][j] = T[i+power(2, j-1)][j-1];
            }
        }
    }

    while (q--) {
        scanf("%d%d", &lo, &hi);
        int l = hi-lo+1;
        int k = log2(l);
        int ans = min(a[T[lo][k]], a[T[lo+l-power(2, k)][k]]);
        printf("%d\n", ans);
    }

    return 0;
}
