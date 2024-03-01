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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        int ans = -1;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            ans = node->val;
            q.pop();
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
        }
        return ans;
    }
};