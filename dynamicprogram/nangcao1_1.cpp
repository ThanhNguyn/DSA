
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, M;
    cin >> n >> M;

    vector<int> w(n + 1), v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<long long>> dp(
        n + 1, vector<long long>(M + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {

            dp[i][j] = dp[i - 1][j];

            if (j >= w[i])
            {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][M];

    return 0;
}
