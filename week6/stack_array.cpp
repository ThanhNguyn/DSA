#include <bits/stdc++.h>
#define MAX 100
using namespace std;

struct Stack
{
    vector<int> arr;
    int top;
};

void Init(Stack &st)
{
    st.top = -1;
};

int isEmpty(Stack &st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
};

int isFull(Stack &st)
{
    if (st.top >= MAX - 1)
    {
        return 1;
    }
    return 0;
};

void Push(Stack &st, int data)
{
    if (!isFull(st))
    {
        st.top++;
        st.arr.push_back(data);
    }
};
int Pop(Stack &st)
{
    int data;
    if (!isEmpty(st))
    {
        data = st.arr.back();
        st.arr.pop_back();
        st.top--;
    }
    return data;
};

int main()
{
    Stack st;
    Init(st);
    Push(st, 6);
    Push(st, 3);
    Push(st, 4);
    int x = Pop(st);
    int y = Pop(st);
    cout << x << " " << y << endl;
}