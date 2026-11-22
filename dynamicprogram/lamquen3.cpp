#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    vector<long long> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 0;
    dp[1] = max(0LL, a[1]);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }

    cout << dp[n];

    return 0;
}
