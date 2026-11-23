
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int k, S;
    cin >> k >> S;

    vector<int> tmp(k);
    for (int i = 0; i < k; i++)
    {
        cin >> tmp[i];
    }

    vector<int> dp;
    dp.assign(S + 1, INF);
    dp[0] = 0;

    for (int x = 1; x <= S; x++)
    {
        for (int i = 0; i < k; i++)
        {
            if (x >= tmp[i])
            {
                dp[x] = min(dp[x], dp[x - tmp[i]] + 1);
            }
        }
    }

    if (dp[S] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << dp[S];
    }

    return 0;
}
