#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<int> s;
    s.push(6);
    s.push(3);
    s.push(4);

    int x = s.top();
    s.pop();
    int y = s.top();
    s.pop();

    return 0;
}