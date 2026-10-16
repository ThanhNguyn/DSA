#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> x;
vector<bool> used;

void print(){
    for (int i = 0; i < n; i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (!used[j]){
            x[i] = j;
            used[j] = true;
            if (i == n - 1){
                print();
            }
            else{
                Try(i + 1);
            }
            used[j] = false;
        }
    }
}

int main(){
    cin >> n;
    x.resize(n);
    used.resize(n + 1, false);
    Try(0);
    return 0;
}