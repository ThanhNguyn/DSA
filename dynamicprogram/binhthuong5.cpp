
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> dp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp[0] = a[0];

    long long ans = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
