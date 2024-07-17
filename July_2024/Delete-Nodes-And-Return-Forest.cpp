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
    TreeNode *f(TreeNode *root, unordered_set<int> &s, vector<TreeNode *> &v)
    {
        if (root == NULL)
            return NULL;
        root->left = f(root->left, s, v);
        root->right = f(root->right, s, v);
        if (s.find(root->val) != s.end())
        {
            if (root->left != NULL)
                v.push_back(root->left);
            if (root->right != NULL)
                v.push_back(root->right);
            return NULL;
        }
        else
        {
            return root;
        }
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> s;
        for (int i = 0; i < to_delete.size(); i++)
        {
            s.insert(to_delete[i]);
        }
        vector<TreeNode *> v;
        f(root, s, v);
        if (s.find(root->val) == s.end())
        {
            v.push_back(root);
        }
        return v;
    }
};