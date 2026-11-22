#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> F;
    F.assign(n + 1, 0);
    F[1] = F[2] = 1;
    for (int k = 3; k <= n; k++)
    {
        F[k] = F[k - 1] + F[k - 2];
    }
    cout << F[n];
    return 0;
}
