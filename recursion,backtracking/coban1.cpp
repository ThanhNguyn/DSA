#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
ll fib(ll n)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 2) + fib(n - 1);
}
int main()
{
    ll n;
    if (cin >> n)
    {
        dp.assign(n + 1, -1); // tao n+1 gia tri -1
        cout << fib(n);
    }
    return 0;
}
