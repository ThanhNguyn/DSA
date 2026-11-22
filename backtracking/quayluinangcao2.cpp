
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<vector<bool>> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool backtrack(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return false;

    if (a[r][c] == 1 || visited[r][c])
        return false;

    visited[r][c] = true;

    if (r == n - 1 && c == n - 1)
        return true;

    for (int d = 0; d < 4; d++)
    {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (backtrack(nr, nc))
            return true;
    }

    visited[r][c] = false;

    return false;
}

int main()
{
    cin >> n;

    a.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    if (backtrack(0, 0))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
