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

    void removeAll(long long x)
    {
        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr)
        {
            if (curr->data == x)
            {
                Node *toDelete = curr;
                if (curr == head)
                {
                    head = curr->next;
                    curr = head;
                    if (head == nullptr)
                    {
                        tail = nullptr;
                    }
                }
                else
                {
                    prev->next = curr->next;
                    if (curr == tail)
                    {
                        tail = prev;
                    }
                    curr = prev->next;
                }
                delete toDelete;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
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

    long long x;
    cin >> x;

    list.removeAll(x);
    list.print();
    list.clear();

    return 0;
}