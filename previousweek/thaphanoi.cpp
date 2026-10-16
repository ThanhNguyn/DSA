#include <bits/stdc++.h>
using namespace std;

long d = 0;
void move(int n, char a, char b, char c){
    if (n == 1){
        cout << "Chuyen dia 1 tu cot " << a << " sang cot " << c << endl;
        d++;
    }
    else{
        move(n - 1, a, c, b);
        move(1, a, b, c);
        move(n - 1, c, b, a);
    }
}
int main(){
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    cout << "So buoc di chuyen la: " << d;
    return 0;
}