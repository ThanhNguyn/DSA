#include <bits/stdc++.h>
using namespace std;

struct TNode
{
    int data;
    TNode *pLeft, *pRight;
    TNode(int x)
    {
        data = x;
        pLeft = nullptr;
        pRight = nullptr;
    }
};

typedef TNode *Tree;
Tree root = new TNode(5);

void LRN(Tree root)
{
    if (root == nullptr)
        return;
    LRN(root->pLeft);
    LRN(root->pRight);
    cout << root->data << " ";
};

void RLN(Tree root)
{
    if (root == nullptr)
        return;
    RLN(root->pRight);
    RLN(root->pLeft);
    cout << root->data << " ";
};

void LNR(Tree root)
{
    if (root == nullptr)
        return;
    LNR(root->pLeft);
    cout << root->data << " ";
    LNR(root->pRight);
}

int count(Tree root)
{
    if (root == nullptr)
        return 0;
    return 1 + count(root->pLeft) + count(root->pRight);
}

int countLeaves(Tree root)
{
    if (root == nullptr)
        return 0;
    if (root->pLeft == nullptr && root->pRight == nullptr)
        return 1;
    return countLeaves(root->pLeft) + countLeaves(root->pRight);
}

int height(Tree root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->pLeft), height(root->pRight));
}

TNode *searchNode(Tree root, int dt)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == dt)
        return root;
    if (root->data > dt)
        return searchNode(root->pLeft, dt);
    return searchNode(root->pRight, dt);
}

bool insertNode(Tree &root, int dt)
{
    if (root == nullptr)
    {
        root = new TNode(dt);
        return 1;
    }
    if (root->data == dt)
        return 0;
    if (root->data > dt)
        return insertNode(root->pLeft, dt);
    return insertNode(root->pRight, dt);
}

bool removeNode(Tree &root, int dt)
{
    if (root == nullptr)
        return 0;
    if (root->data > dt)
        return removeNode(root->pLeft, dt);
    if (root->data < dt)
        return removeNode(root->pRight, dt);

    if (root->pLeft == nullptr)
    {
        TNode *temp = root;
        root = root->pRight;
        delete temp;
        return 1;
    }
    if (root->pRight == nullptr)
    {
        TNode *temp = root;
        root = root->pLeft;
        delete temp;
        return 1;
    }
    TNode *successor = root->pRight;
    while (successor->pLeft != nullptr)
    {
        successor = successor->pLeft;
    }
    root->data = successor->data;
    return removeNode(root->pRight, dt);
}
int main()
{
    root->pLeft = new TNode(3);
    root->pLeft->pLeft = new TNode(0);
    root->pLeft->pRight = new TNode(6);
    root->pRight = new TNode(7);
    root->pRight->pLeft = new TNode(5);
    root->pRight->pRight = new TNode(6);
    root->pLeft->pLeft->pLeft = new TNode(10);

    LRN(root);
    cout << "\n";
    RLN(root);
    cout << "\n";
    cout << count(root) << "\n";
    cout << countLeaves(root) << "\n";
    cout << height(root);
    TNode *ans = searchNode(root, 7);
    if (ans == nullptr)
    {
        cout << "\nKo tim thay gia tri";
    }
    else
        cout << "\nTim thay gia tri" << endl;
    insertNode(root, 2);
    cout << "\n";
    LNR(root);
    removeNode(root, 3);
    return 0;
}