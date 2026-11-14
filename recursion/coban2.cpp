#include <bits/stdc++.h>
using namespace std;

void revertString(string s, int i)
{
    if (i < 0)
        return;
    cout << s[i];
    return revertString(s, i - 1);
}
int main()
{
    string s;
    getline(cin, s);
    revertString(s, s.size() - 1);
    return 0;
}
