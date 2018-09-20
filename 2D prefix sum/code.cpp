#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;

    cin>>m>>n;
    int a[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }

    int pre[m][n];
    pre[0][0] = a[0][0];

    for (int i = 1; i < n; i++) {
        pre[i][0] = pre[i-1][0] + a[i][0];
    }

    for (int j = 1; j < m; j++) {
        pre[0][j] = pre[0][j-1] + a[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] + a[i][j] - pre[i-1][j-1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<pre[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
