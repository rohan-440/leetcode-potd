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
/*
a

ab
ac

abd    dba
abe    eba

acd    dca
ace    eca

z
zb
zd

zbb  bbz
zbd  dbz

zda   adz
zdc   cdz



c
cc cb
ccd
dca
ccba
cba


*/
class Solution
{
public:
    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "";
        queue<pair<TreeNode *, string>> q;
        q.push({root, string(1, char(root->val + 'a'))});
        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            string s = q.front().second;
            q.pop();
            if (node->left)
                q.push({node->left, s + char(node->left->val + 'a')});
            if (node->right)
                q.push({node->right, s + char(node->right->val + 'a')});
            if (!node->left && !node->right)
            {
                reverse(s.begin(), s.end());
                ans = min(ans, s);
            }
        }
        return ans;
    }
};