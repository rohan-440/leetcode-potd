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
    bool preOrder(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return root->val;
        bool l = preOrder(root->left);
        bool r = preOrder(root->right);
        if (root->val == 2)
            return l | r;
        if (root->val == 3)
            return l & r;
        return root->val;
    }
    bool evaluateTree(TreeNode *root)
    {
        return preOrder(root);
    }
};