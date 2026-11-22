
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<bool>> visited;

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool backtrack(int row, int col, int step)
{

    if (step == n * n)
        return true;

    for (int d = 0; d < 8; d++)
    {

        int nr = row + dr[d];
        int nc = col + dc[d];

        if (nr >= 0 && nr < n &&
            nc >= 0 && nc < n &&
            !visited[nr][nc])
        {

            visited[nr][nc] = true;

            if (backtrack(nr, nc, step + 1))
                return true;

            visited[nr][nc] = false;
        }
    }

    return false;
}

int main()
{
    int r, c;
    cin >> n >> r >> c;

    r--;
    c--;

    visited.assign(n, vector<bool>(n, false));

    visited[r][c] = true;

    if (n % 2 == 1 && (r + c) % 2 != 0)
    {
        cout << "NO";
        return 0;
    }

    if (backtrack(r, c, 1))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
