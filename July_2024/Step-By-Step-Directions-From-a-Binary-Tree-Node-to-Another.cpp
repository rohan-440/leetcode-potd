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
    TreeNode *lca(TreeNode *root, int p, int q)
    {
        if (root == NULL || root->val == p || root->val == q)
            return root;
        TreeNode *l = lca(root->left, p, q);
        TreeNode *r = lca(root->right, p, q);
        if (l == NULL && r == NULL)
            return NULL;
        if (l != NULL && r == NULL)
            return l;
        if (l == NULL && r != NULL)
            return r;
        return root;
    }
    bool findPath(TreeNode *root, int value, string &temp)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->val == value)
            return true;
        temp.push_back('L');
        if (findPath(root->left, value, temp))
            return true;
        temp.pop_back();
        temp.push_back('R');
        if (findPath(root->right, value, temp))
            return true;
        temp.pop_back();
        return false;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *node = lca(root, startValue, destValue);
        string lca_src = "";
        string lca_dest = "";
        findPath(node, startValue, lca_src);
        findPath(node, destValue, lca_dest);
        for (int i = 0; i < lca_src.size(); i++)
            lca_src[i] = 'U';
        return lca_src + lca_dest;
    }
};
