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
    int sum = 0;
    void f(TreeNode *root)
    {
        if (root == NULL)
            return;
        f(root->left);
        if (root->left && (root->left->left == NULL && root->left->right == NULL))
        {
            sum += root->left->val;
        }

        f(root->right);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {

        f(root);
        return sum;
    }
};