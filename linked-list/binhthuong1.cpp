
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

    int x, y;
    cin >> x >> y;

    Node *cur = head;

    while (cur != nullptr && cur->data != x)
    {
        cur = cur->next;
    }

    if (cur != nullptr)
    {
        Node *p = new Node;
        p->data = y;

        p->next = cur->next;
        cur->next = p;

        if (tail == cur)
        {
            tail = p;
        }
    }

    if (head == nullptr)
    {
        cout << "EMPTY";
    }
    else
    {
        Node *p = head;

        while (p != nullptr)
        {
            cout << p->data;

            if (p->next != nullptr)
            {
                cout << " ";
            }

            p = p->next;
        }
    }

    while (head != nullptr)
    {
        Node *p = head;
        head = head->next;
        delete p;
    }

    return 0;
}
