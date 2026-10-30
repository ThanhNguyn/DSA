#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};

void init(List &l) {
    l.head = l.tail = nullptr;
}

Node* createNode(int value) {
    Node* p = new Node;
    p->value = value;
    p->next = nullptr;
    return p;
}

// 1. Add one node at first
void add_head(List &l, Node* newNode) {
    if (!newNode) return;
    if (!l.head) {
        l.head = l.tail = newNode;
    } else {
        newNode->next = l.head;
        l.head = newNode;
    }
}

// 3. Add many node at first
void add_many_head(List &l, int values[], int count) {
    for (int i = count - 1; i >= 0; i--)
        add_head(l, createNode(values[i]));
}

// 2. Add one node at last
void add_tail(List &l, Node* newNode) {
    if (!newNode) return;
    if (!l.tail) {
        l.head = l.tail = newNode;
    } else {
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

// 4. Add many node at last
void add_many_tail(List &l, int values[], int count) {
    for (int i = 0; i < count; i++)
        add_tail(l, createNode(values[i]));
}

// 5. Add one node after select node
void add_next(List &l, Node* prevNode, Node* newNode) {
    if (!prevNode || !newNode) return;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    if (prevNode == l.tail) l.tail = newNode;
}

// 6. Display List
void print_list(List &l) {
    if (!l.head) {
        cout << "List is empty.\n";
        return;
    }
    Node* cur = l.head;
    while (cur) {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << "\n";
}

// 7. Find one node
Node* find_node(List &l, int value) {
    Node* cur = l.head;
    while (cur) {
        if (cur->value == value) return cur;
        cur = cur->next;
    }
    return nullptr;
}

void search(List &l, int value) {
    Node* f = find_node(l, value);
    if (f) cout << "Found: " << value << "\n";
    else cout << "Not found: " << value << "\n";
}

// 8. Select and display n(th) node
Node* get_nth_node(List &l, int n) {
    if (n < 1) return nullptr;
    Node* cur = l.head;
    int c = 1;
    while (cur) {
        if (c == n) return cur;
        cur = cur->next;
        c++;
    }
    return nullptr;
}

void display_nth_node(List &l, int n) {
    Node* node = get_nth_node(l, n);
    if (node) cout << "Node " << n << " = " << node->value << "\n";
    else cout << "Node " << n << " does not exist.\n";
}

// 9. Display node count
int count_nodes(List &l) {
    int c = 0;
    Node* cur = l.head;
    while (cur) { c++; cur = cur->next; }
    return c;
}

void display_count(List &l) {
    cout << "Node count: " << count_nodes(l) << "\n";
}

// 10. Remove one node
bool remove_node(List &l, int value) {
    if (!l.head) return false;
    if (l.head->value == value) {
        Node* temp = l.head;
        l.head = l.head->next;
        if (!l.head) l.tail = nullptr;
        delete temp;
        return true;
    }
    Node* cur = l.head;
    while (cur->next && cur->next->value != value) cur = cur->next;
    if (!cur->next) return false;
    Node* toDelete = cur->next;
    cur->next = toDelete->next;
    if (toDelete == l.tail) l.tail = cur;
    delete toDelete;
    return true;
}

// 11. Remove List
void remove_list(List &l) {
    Node* cur = l.head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    l.head = l.tail = nullptr;
}

// 12. Get sum of all nodes
int sum_nodes(List &l) {
    int s = 0;
    Node* cur = l.head;
    while (cur) { s += cur->value; cur = cur->next; }
    return s;
}

void display_sum(List &l) {
    cout << "Sum of all nodes: " << sum_nodes(l) << "\n";
}

// 13. Inserting a new node in a sorted list (tang dan)
void insert_sorted(List &l, Node* newNode) {
    if (!newNode) return;
    if (!l.head || l.head->value >= newNode->value) {
        add_head(l, newNode);
        return;
    }
    if (l.tail->value <= newNode->value) {
        add_tail(l, newNode);
        return;
    }
    Node* cur = l.head;
    while (cur->next && cur->next->value < newNode->value) cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
}

int main() {
    List intList;
    init(intList);
    List sortedList;
    init(sortedList);
    int choice;
    do {
        cout << "\n===== MENU DANH SACH LIEN KET =====\n";
        cout << "1. Add one node at first\n";
        cout << "2. Add one node at last\n";
        cout << "3. Add many node at first\n";
        cout << "4. Add many node at last\n";
        cout << "5. Add one node after select node\n";
        cout << "6. Display List\n";
        cout << "7. Find one node\n";
        cout << "8. Select and display n(th) node\n";
        cout << "9. Display node count\n";
        cout << "10. Remove one node\n";
        cout << "11. Remove List\n";
        cout << "12. Get sum of all nodes\n";
        cout << "13. Inserting a new node in a sorted list\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1: {
                int v; cout << "Enter value: "; cin >> v;
                add_head(intList, createNode(v));
                break;
            }
            case 2: {
                int v; cout << "Enter value: "; cin >> v;
                add_tail(intList, createNode(v));
                break;
            }
            case 3: {
                int n; cout << "Enter count: "; cin >> n;
                if (n <= 0) { cout << "Invalid count.\n"; break; }
                int* arr = new int[n];
                cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                add_many_head(intList, arr, n);
                delete[] arr;
                break;
            }
            case 4: {
                int n; cout << "Enter count: "; cin >> n;
                if (n <= 0) { cout << "Invalid count.\n"; break; }
                int* arr = new int[n];
                cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                add_many_tail(intList, arr, n);
                delete[] arr;
                break;
            }
            case 5: {
                int prevVal, newVal;
                cout << "Enter value of node after which to insert: "; cin >> prevVal;
                Node* prev = find_node(intList, prevVal);
                if (!prev) { cout << "Previous node not found.\n"; break; }
                cout << "Enter new value: "; cin >> newVal;
                add_next(intList, prev, createNode(newVal));
                break;
            }
            case 6: {
                cout << "List: ";
                print_list(intList);
                break;
            }
            case 7: {
                int v; cout << "Enter value to find: "; cin >> v;
                search(intList, v);
                break;
            }
            case 8: {
                int n; cout << "Enter position n: "; cin >> n;
                display_nth_node(intList, n);
                break;
            }
            case 9: {
                display_count(intList);
                break;
            }
            case 10: {
                int v; cout << "Enter value to remove: "; cin >> v;
                if (remove_node(intList, v)) cout << "Removed " << v << "\n";
                else cout << "Value not found.\n";
                break;
            }
            case 11: {
                remove_list(intList);
                cout << "List removed.\n";
                break;
            }
            case 12: {
                display_sum(intList);
                break;
            }
            case 13: {
                int v; cout << "Enter value to insert into sorted list: "; cin >> v;
                insert_sorted(sortedList, createNode(v));
                cout << "Sorted list: ";
                print_list(sortedList);
                break;
            }
            case 0: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice.\n";
            }
        }
    } while (choice != 0);

    remove_list(intList);
    remove_list(sortedList);
    return 0;
}
