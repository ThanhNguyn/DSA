#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    int n;
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node *p = new Node;
        p->data = x;
        p->next = nullptr;

        if (head == nullptr)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    int x;
    cin >> x;
    int firstPos = -1;
    int count = 0;
    int pos = 1;

    Node *p = head;

    while (p != nullptr)
    {
        if (p->data == x)
        {
            if (firstPos == -1)
            {
                firstPos = pos;
            }

            count++;
        }

        p = p->next;
        pos++;
    }

    cout << firstPos << " " << count;

    while (head != nullptr)
    {
        Node *p = head;
        head = head->next;
        delete p;
    }

    return 0;
}