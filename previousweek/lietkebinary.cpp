#include <iostream>
using namespace std;

#define MAX 100

int x[MAX];
int n;

void Inkq(){
    for (int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == n){
            Inkq();
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    cin >> n;
    Try(1);
    return 0;
}