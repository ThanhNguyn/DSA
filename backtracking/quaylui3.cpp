#include <bits/stdc++.h>
using namespace std;

int target, n;
vector<int> x;
bool Try(int i, int sum){
    if(sum == target) return 1;
    if(i == n || sum >target) return 0;
    return Try(i + 1, sum + x[i]) ||
       Try(i + 1, sum);
}

int main(){
    cin >> n;
    x.assign(n,0);
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        S += x[i];
    }

    if (S % 2 != 0)
    {
        cout << "NO";
        return 0;
    }

    target = S / 2;

    cout << (Try(0, 0) ? "YES" : "NO");

    return 0;
}