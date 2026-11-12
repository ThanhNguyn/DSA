#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum(ll n)
{
    if (n < 10)
        return n;
    return n % 10 + sum(n / 10);
}
int main()
{
    ll n;
    cin >> n;
    cout << sum(n);
    return 0;
}
