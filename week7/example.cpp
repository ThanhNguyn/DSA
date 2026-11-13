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
    return 0;
}