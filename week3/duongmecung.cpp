#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<bool>> visited;
vector<string> ans;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

void Try(int x, int y, string path)
{
    if (x == n - 1 && y == m - 1)
    {
        ans.push_back(path);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0 && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            Try(nx, ny, path + dir[i]);
            visited[nx][ny] = false;
        }
    }
}

int main()
{
    if (!(cin >> n >> m))
        return 0;

    a.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    if (a[0][0] == 0 && a[n - 1][m - 1] == 0)
    {
        visited[0][0] = true;
        Try(0, 0, "");
    }

    if (ans.empty())
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << ans.size() << "\n";
        for (const string &s : ans)
        {
            cout << s << "\n";
        }
    }

    return 0;
}