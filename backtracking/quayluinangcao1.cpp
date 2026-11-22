#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
vector<bool> col, diag1, diag2;

void backtrack(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        int d1 = row - c + n - 1;
        int d2 = row + c;

        if (!col[c] && !diag1[d1] && !diag2[d2])
        {
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            backtrack(row + 1);

            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
}
int main()
{
    cin >> n;

    col.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);
    cin >> n;
    backtrack(0);
    cout << ans;
    return 0;
}
