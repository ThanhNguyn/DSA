#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll giaiThua(ll n)
{
    if (n == 0)
        return 1;
    return n * giaiThua(n - 1);
}
int main()
{
    ll n;
    if (cin >> n)
        cout << giaiThua(n);
    return 0;
}
