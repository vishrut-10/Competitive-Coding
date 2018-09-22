#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

long long fast_modulo_multiplication(long long x, long long y)
{
    if (y == 0) return 1;
    if (y == 1) return x;

    if (y%2 == 0) {
        long long temp = fast_modulo_multiplication(x, y/2);
        temp = temp*temp;
        temp %= M;

        return temp;
    } else {
        long long temp = x*fast_modulo_multiplication(x, y-1);
        temp %= M;

        return temp;
    }
}

int main()
{
    long long x, y;
    long long ans;

    scanf("%lld%lld", &x, &y);
    ans = fast_modulo_multiplication(x, y);

    printf("%lld\n", ans);

    return 0;
}
