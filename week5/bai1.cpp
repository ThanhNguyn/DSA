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

Node *createNode(int value)
{
    Node *p = new Node;
    p->value = value;
    p->next = nullptr;
    return p;
}

// 1. Add one node at first
void add_head(List &l, Node *newNode)
{
    if (newNode == nullptr) return;
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

// 3. Add many node at first
void add_many_head(List &l, int values[], int count)
{
    for (int i = count - 1; i >= 0; i--)
    {
        add_head(l, createNode(values[i]));
    }
}

// 2. Add one node at last
void add_tail(List &l, Node *newNode)
{
    if (newNode == nullptr) return;
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

// 4. Add many node at last
void add_many_tail(List &l, int values[], int count)
{
    for (int i = 0; i < count; i++)
    {
        add_tail(l, createNode(values[i]));
    }
}

// 5. Add one node after select node
void add_next(List &l, Node *prevNode, Node *newNode)
{
    if (prevNode == nullptr || newNode == nullptr) return;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    if (prevNode == l.tail)
    {
        l.tail = newNode;
    }
}

// 6. Display List
void print_list(List &l)
{
    if (l.head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *current = l.head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// 7. Find one node
Node *find_node(List &l, int value)
{
    Node *current = l.head;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void search(List &l, int value)
{
    Node *found = find_node(l, value);
    if (found != nullptr)
    {
        cout << "Found: " << value << endl;
    }
    else
    {
        cout << "Not found: " << value << endl;
    }
}

// 8. Select and display n(th) node (1-based index)
Node *get_nth_node(List &l, int n)
{
    if (n < 1) return nullptr;
    Node *current = l.head;
    int count = 1;
    while (current != nullptr)
    {
        if (count == n) return current;
        current = current->next;
        count++;
    }
    return nullptr;
}

void display_nth_node(List &l, int n)
{
    Node *node = get_nth_node(l, n);
    if (node != nullptr)
    {
        cout << "Node " << n << " = " << node->value << endl;
    }
    else
    {
        cout << "Node " << n << " does not exist." << endl;
    }
}

// 9. Display node count
int count_nodes(List &l)
{
    int count = 0;
    Node *current = l.head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void display_count(List &l)
{
    cout << "Node count: " << count_nodes(l) << endl;
}

// 10. Remove one node (by value)
bool remove_node(List &l, int value)
{
    if (l.head == nullptr) return false;

    if (l.head->value == value)
    {
        Node *temp = l.head;
        l.head = l.head->next;
        if (l.head == nullptr) l.tail = nullptr;
        delete temp;
        return true;
    }

    Node *current = l.head;
    while (current->next != nullptr && current->next->value != value)
    {
        current = current->next;
    }

    if (current->next == nullptr) return false;

    Node *toDelete = current->next;
    current->next = toDelete->next;
    if (toDelete == l.tail) l.tail = current;
    delete toDelete;
    return true;
}

// 11. Remove List
void remove_list(List &l)
{
    Node *current = l.head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    l.head = nullptr;
    l.tail = nullptr;
}

// 12. Get sum of all nodes
int sum_nodes(List &l)
{
    int sum = 0;
    Node *current = l.head;
    while (current != nullptr)
    {
        sum += current->value;
        current = current->next;
    }
    return sum;
}

void display_sum(List &l)
{
    cout << "Sum of all nodes: " << sum_nodes(l) << endl;
}

// 13. Inserting a new node in a sorted list (tang dan)
void insert_sorted(List &l, Node *newNode)
{
    if (newNode == nullptr) return;

    if (l.head == nullptr || l.head->value >= newNode->value)
    {
        add_head(l, newNode);
        return;
    }

    if (l.tail->value <= newNode->value)
    {
        add_tail(l, newNode);
        return;
    }

    Node *current = l.head;
    while (current->next != nullptr && current->next->value < newNode->value)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

List intList;

int main()
{
    init(intList);

    add_head(intList, createNode(10));
    add_tail(intList, createNode(20));
    cout << "After add_head(10), add_tail(20): ";
    print_list(intList);

    int arr1[] = {1, 2, 3};
    add_many_head(intList, arr1, 3);
    cout << "After add_many_head({1,2,3}): ";
    print_list(intList);

    int arr2[] = {30, 40, 50};
    add_many_tail(intList, arr2, 3);
    cout << "After add_many_tail({30,40,50}): ";
    print_list(intList);

    cout << "Display List: ";
    print_list(intList);

    search(intList, 40);
    search(intList, 99);

    display_nth_node(intList, 1);
    display_nth_node(intList, 5);
    display_nth_node(intList, 100);

    display_count(intList);
    display_sum(intList);

    remove_node(intList, 20);
    cout << "After remove_node(20): ";
    print_list(intList);
    display_count(intList);

    List sortedList;
    init(sortedList);
    insert_sorted(sortedList, createNode(20));
    insert_sorted(sortedList, createNode(10));
    insert_sorted(sortedList, createNode(30));
    insert_sorted(sortedList, createNode(25));
    cout << "Sorted list after inserts: ";
    print_list(sortedList);

    remove_list(intList);
    remove_list(sortedList);

    return 0;
}