#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<ll> dp;
    dp[0] = 1;
    int n;
    cin >> n;
    dp.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] += dp[j - 1];
        }
    }
    cout << dp[n];

    return 0;
}
