#include <bits/stdc++.h>
using namespace std;

int giaithua(int n){
    int gt = 1;
    for (int i = n; i > 0; i--){
        gt *= i;
    }
    return gt;
}

