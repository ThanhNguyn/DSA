#include <bits/stdc++.h>
using namespace std;

const int n = 4;

string name[n]= {"AN", "Binh", "Chi", "Dung"};

string pos[n];

bool used[n] = {false}; //<bool> used(n, false);


bool check(int slot, int nameIndex){
    if(used[nameIndex]) return false;
    if(nameIndex == 0 && slot == 0) return false;
    if(nameIndex == 3 && slot == 3) return false;
    if(nameIndex == 2 && !used[1]) return false;
        return true;
}

void Try(int slot){
    for(int i = 0; i < n; i++){
        if(check(slot, i)){
            pos[slot] = name[i];
            used[i] = true;
            if(slot == n - 1){
                for(int j = 0; j < n; j++){
                    cout << pos[j] << " ";
                }
                cout << endl;
            }
            else{
                Try(slot + 1);
            }
            used[i] = false;
        }
    }
};
int main(){
    Try(0);
}