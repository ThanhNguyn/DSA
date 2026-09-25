#include <iostream>
#include <vector>
using namespace std;

vector<bool> doc;
vector<bool> cheo1;
vector<bool> cheo2;

int n;

// i is the row, j is the column
void Attempt(int i){
    for(int j = 1;j <= n; j++){
        if(!doc[j] && !cheo1[i + j] && !cheo2[i - j + n]){
            doc[j] = true;
            cheo1[i + j] = true;
            cheo2[i - j + n] = true;
            if(i == n){
            }
            else{
                Attempt(i + 1);
            }
            doc[j] = false;
            cheo1[i + j] = false;
            cheo2[i - j + n] = false;
        }
    }
};