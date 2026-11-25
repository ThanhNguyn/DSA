
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
        char type;
        int x;
        cin >> type >> x;

        Node *p = new Node;
        p->data = x;
        p->next = nullptr;

        if (type == 'H')
        {
            p->next = head;
            head = p;

            if (tail == nullptr)
            {
                tail = p;
            }
        }
        else if (type == 'T')
        {
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
