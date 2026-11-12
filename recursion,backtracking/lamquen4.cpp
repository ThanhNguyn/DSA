#include <bits/stdc++.h>
using namespace std;

int recursion(int a, int b)
{
    if (b == 0)
        return a;
    return recursion(b, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << recursion(a, b);
    return 0;
}
