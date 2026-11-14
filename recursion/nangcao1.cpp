#include <bits/stdc++.h>
using namespace std;

void tower(int n, char A, char B, char C)
{
    if (n == 0)
        return;
    tower(n - 1, A, C, B);
    cout << A << " " << C << "\n";
    tower(n - 1, B, A, C);
}
int main()
{
    int n;
    cin >> n;
    cout << (long long)pow(2, n) - 1 << '\n';
    tower(n, 'A', 'B', 'C');
    return 0;
}
