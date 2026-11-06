#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *top;
};

void Init(Stack &st)
{
    st.top = nullptr;
};

int isEmpty(Stack &st)
{
    return st.top == nullptr ? 1 : 0;
};

void Push(Stack &st, int data)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        cout << "Not enough memory" << endl;
        return;
    }
    newNode->data = data;
    newNode->next = nullptr;
    if (st.top == nullptr)
    {
        st.top = newNode;
    }
    else
    {
        newNode->next = st.top;
        st.top = newNode;
    }
};

int Pop(Stack &st)
{
    if (st.top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    int x;
    Node *p = st.top;
    st.top = st.top->next;
    x = p->data;
    delete p;
    return x;
};

int main()
{
    Stack st;
    Init(st);
    Push(st, 5);
    Push(st, 9);
    Push(st, 3);
    int x = Pop(st);
    int y = Pop(st);
    cout << x << " " << y << endl;
    return 0;
}