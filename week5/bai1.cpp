#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
struct List
{
    Node *head;
    Node *tail;
};

void init(List &l)
{
    l.head = nullptr;
    l.tail = nullptr;
}
void add_head(List &l, Node *newNode)
{
    if (l.head == nullptr)
    {
        l.head = newNode;
        l.tail = newNode;
    }
    else
    {
        newNode->next = l.head;
        l.head = newNode;
    }
}
void add_tail(List &l, Node *newNode)
{
    if (l.tail == nullptr)
    {
        l.head = newNode;
        l.tail = newNode;
    }
    else
    {
        l.tail->next = newNode;
        l.tail = newNode;
    }
}
void add_next(List &l, Node *prevNode, Node *newNode)
{
    if (prevNode != nullptr)
    {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        if (prevNode == l.tail)
        {
            l.tail = newNode;
        }
    }
}
void print_list(List &l)
{
    Node *current = l.head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
void search(List &l, int value)
{
    Node *current = l.head;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            cout << "Found: " << value << endl;
            return;
        }
        current = current->next;
    }
    cout << "Not found: " << value << endl;
}
int removeHead(List &l)
{
    if (l.head == nullptr)
    {
        return -1;
    }
    Node *temp = l.head;
    int removedValue = temp->value;
    l.head = l.head->next;
    if (l.head == nullptr)
    {
        l.tail = nullptr;
    }
    delete temp;
    return removedValue;
}

List intList;

int main()
{
    init(intList);
    Node newNode;
    newNode.value = 6;
    newNode.next = nullptr;
    add_head(intList, &newNode);
    add_tail(intList, &newNode);
    Node node2;
    node2.value = 8;
    node2.next = nullptr;
    add_tail(intList, &node2);
    print_list(intList);
    search(intList, 8);
    removeHead(intList);
    print_list(intList);
    return 0;
}