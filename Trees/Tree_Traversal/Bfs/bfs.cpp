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

vector<vector<int>> levelOrder(TreeNode *root)
{

    vector<vector<int>> lvlorder;

    if (root == nullptr)
        return lvlorder;

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {

        int n = q.size();

        vector<int> lvl(n);

        for (int i = 0; i < n; i++)
        {

            TreeNode *node = q.front();

            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            lvl[i] = node->val;
        }

        lvlorder.push_back(lvl);
    }

    return lvlorder;
}

int main()
{

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    vector<vector<int>> ans = levelOrder(root);

    for (int i = 1; i < ans.size(); i++)
    {

        cout << "level" << i << endl;

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}