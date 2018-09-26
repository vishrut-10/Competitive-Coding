#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void multiply(ll F[2][2], ll M[2][2])
{
    ll x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    ll y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    ll z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    ll w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(ll F[2][2], int n)
{
    if (n == 0 || n == 1) return;

    ll M[2][2] = { {1, 1}, {1, 0} };
    power(F, n/2);
    multiply(F, F);

    if (n%2 == 1) multiply(F, M);
}

ll matrix_exponentiation(int n)
{
    if (n == 0) return 0;

    ll F[2][2] = { {1, 1}, {1, 0} };
    power(F, n);

    return F[0][0];
}

int main()
{
    int n;

    scanf("%d", &n);
    ll nfib = matrix_exponentiation(n);

    printf("%lld\n", nfib);

    return 0;
}
