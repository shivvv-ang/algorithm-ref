#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode *root, vector<int> &traversal)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left, traversal);
    traversal.push_back(root->val);
    inorderTraversal(root->right, traversal);
}

void preorderTraversal(TreeNode *root, vector<int> &traversal)
{
    if (root == nullptr)
        return;

    traversal.push_back(root->val);

    preorderTraversal(root->left, traversal);
    preorderTraversal(root->right, traversal);
}

void postorderTraversal(TreeNode *root, vector<int> &traversal)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left, traversal);
    postorderTraversal(root->right, traversal);
    traversal.push_back(root->val);
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    vector<int> inorder, preorder, postorder;

    inorderTraversal(root, inorder);

    preorderTraversal(root, preorder);

    postorderTraversal(root, postorder);

    for (int x : inorder)
        cout << x << " ";

    cout << "\n";

    for (int x : preorder)
        cout << x << " ";

    cout << "\n";

    for (int x : postorder)
        cout << x << " ";

    cout << "\n";

    return 0;
}