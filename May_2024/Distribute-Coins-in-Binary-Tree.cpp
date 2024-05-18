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
    int moves = 0;
    int postOrd(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = postOrd(root->left);
        int r = postOrd(root->right);

        int coins = l + r + root->val - 1;
        moves += abs(coins);
        return coins;
    }
    int distributeCoins(TreeNode *root)
    {
        postOrd(root);
        return moves;
    }
};