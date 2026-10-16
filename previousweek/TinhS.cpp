#include <bits/stdc++.h>
using namespace std;

double tong(int n) {
    if(n==1) 
        return 1;
    else
        return tong(n-1) + (double)1/n;
}

int main() {
    int n;
    cin >> n;
    cout << tong(n);
    return 0;
}