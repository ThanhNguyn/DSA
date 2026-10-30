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
void addHead(List &l, Node *newNode)
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

List intList;

int main()
{
    init(intList);
    Node newNode;
    newNode.value = 5;
    newNode.next = nullptr;
    addHead(intList, &newNode);
}