#include <bits/stdc++.h>
using namespace std;

vector<int> x;
int n;

void backtrack(int i, int sum)
{
    for (int j = x[i - 1]; j <= n - sum; j++)
    {
        x[i] = j;

        if (sum + j == n)
        {
            for (int t = 1; t <= i; t++)
            {
                cout << x[t];
                if (t < i)
                    cout << "+";
            }
            cout << "\n";
        }
        else
        {
            backtrack(i + 1, sum + j);
        }
    }
}
int main()
{
    cin >> n;
    x.assign(n + 1, 0);
    x[0] = 1;
    backtrack(1, 0);
}