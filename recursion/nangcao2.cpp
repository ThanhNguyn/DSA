#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> x;
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << x[i];
            }
            cout << "\n";
        }
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    cin >> n;
    x.assign(n + 1, -1);
    Try(1);
    return 0;
}
