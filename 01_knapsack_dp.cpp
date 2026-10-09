
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> w(N + 1), v(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    // dp[i][j]: gia tri lon nhat khi xet i vat,
    // voi suc chua toi da j
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // Khong chon vat i
            dp[i][j] = dp[i - 1][j];

            // Neu chon vat i thi phai du suc chua
            if (w[i] <= j) {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i - 1][j - w[i]] + v[i]
                );
            }
        }
    }

    cout << dp[N][M] << '\n';

    return 0;
}