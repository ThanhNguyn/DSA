#include <iostream>

using namespace std;

struct Node
{
    long long data;
    Node *next;

    Node(long long val)
    {
        data = val;
        next = nullptr;
    }
};

struct LinkedList
{
    Node *head = nullptr;
    Node *tail = nullptr;

    void pushBack(long long val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        tail = head;

        while (curr != nullptr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }
    void print() const
    {
        if (head == nullptr)
        {
            cout << "EMPTY\n";
            return;
        }

        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data;
            if (curr->next != nullptr)
            {
                cout << ' ';
            }
            curr = curr->next;
        }
        cout << '\n';
    }

    void clear()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = tail = nullptr;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    LinkedList list;
    for (int i = 0; i < n; ++i)
    {
        long long val;
        cin >> val;
        list.pushBack(val);
    }

    list.reverse();
    list.print();
    list.clear();

    return 0;
}