#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> x, y;
ll Y(int n);
ll X(int n)
{
    if (n == 0)
        return 1;
    if (x[n] != -1)
        return x[n];
    return x[n] = X(n - 1) + Y(n - 1);
}
ll Y(int n)
{
    if (n == 0)
        return 1;
    if (y[n] != -1)
        return y[n];
    return y[n] = 2 * X(n - 1) + Y(n - 1);
}
int main()
{
    int n;
    cin >> n;
    x.assign(n + 1, -1);
    y.assign(n + 1, -1);
    cout << X(n) << " " << Y(n);
    return 0;
}
