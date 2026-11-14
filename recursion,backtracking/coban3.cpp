#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastPow(ll a, int n)
{
    if (n == 0)
        return 1;
    ll half = pow(a, n / 2);
    if (n % 2 == 0)
        return half * half;
    return half * half * a;
}
int main()
{
    ll a;
    int n;
    if (cin >> a >> n)
        cout << fastPow(a, n);
    return 0;
}
