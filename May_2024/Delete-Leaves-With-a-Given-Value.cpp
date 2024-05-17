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
    TreeNode *postOrd(TreeNode *root, int tar)
    {
        if (root == NULL)
            return NULL;
        TreeNode *l = postOrd(root->left, tar);
        TreeNode *r = postOrd(root->right, tar);
        if (l == NULL && r == NULL && root->val == tar)
            return NULL;
        root->left = l;
        root->right = r;
        return root;
    }
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        return postOrd(root, target);
    }
};