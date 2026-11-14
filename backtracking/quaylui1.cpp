#include <bits/stdc++.h>
using namespace std;
vector<int> x;
int n, M, cnt;

void input()
{
    cin >> n >> M;
    x.assign(n + 1, 0);
    for (int j = 1; j <= n; j++)
    {
        cin >> x[j];
    }
}
void Try(int i, int sum)
{
    if (i > n)
    {
        if (sum == M)
            cnt++;
        return;
    }
    Try(i + 1, sum + x[i]);
    Try(i + 1, sum);
}

int main()
{
    input();
    Try(1, 0);
    cout << cnt;
}