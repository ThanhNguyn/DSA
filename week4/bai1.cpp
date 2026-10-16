#include <bits/stdc++.h>
using namespace std;

int n;
int T = 9;
vector<int> arr;
vector<int> cur;
int curSum = 0;

void print(){
    cout << "[";
    for(int i = 0; i < cur.size(); i++){
        cout << cur[i];
        if(i < cur.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

void Try(int index){
     if(curSum == T){
        print();
        return;
    }
    if(curSum > T) return;

    for(int j = index; j < n; j++){
        cur.push_back(arr[j]);
        curSum += arr[j];

        Try(j + 1);

        curSum -= arr[j];
        cur.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Try(0);
}