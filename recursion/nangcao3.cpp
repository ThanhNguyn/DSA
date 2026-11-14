#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> x, used;
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (used[j] == 0)
        {
            x[i] = j;
            used[j] = 1;
            if (i == n)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << x[i] << " ";
                }
                cout << "\n";
            }
            else
            {
                Try(i + 1);
            }
            used[j] = 0;
        }
    }
}
int main()
{
    cin >> n;
    x.assign(n + 1, -1);
    used.assign(n + 1, 0);
    Try(1);
    return 0;
}
