/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, root->val});
        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int curr = q.front().second;
            q.pop();
            if (node->left)
                q.push({node->left, curr * 10 + node->left->val});
            if (node->right)
                q.push({node->right, curr * 10 + node->right->val});
            if (node->left == NULL && node->right == NULL)
                sum += curr;
        }
        return sum;
    }
};