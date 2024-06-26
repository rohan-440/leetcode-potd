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
    TreeNode *ConstructBst(int l, int r, vector<TreeNode *> &v)
    {
        if (l > r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode *temp = v[mid];
        temp->left = ConstructBst(l, mid - 1, v);
        temp->right = ConstructBst(mid + 1, r, v);
        return temp;
    }
    void inOrder(TreeNode *root, vector<TreeNode *> &v)
    {
        if (root == NULL)
            return;
        inOrder(root->left, v);
        v.push_back(root);
        inOrder(root->right, v);
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> v;
        inOrder(root, v);

        return ConstructBst(0, v.size() - 1, v);
    }
};