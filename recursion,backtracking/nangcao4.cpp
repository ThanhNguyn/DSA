#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> x;

void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n; j++)
    {
        x[i] = j;
        if (i == k)
        {
            for (int t = 1; t <= k; t++)
                cout << x[t] << " ";
            cout << "\n";
        }
        else
        {
            Try(i + 1);
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n >> k;
    x.assign(n + 1, 0);
    Try(1);
}
