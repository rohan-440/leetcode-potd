/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        while (head != NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }
        vector<int> vr = v;
        reverse(vr.begin(), vr.end());
        return vr == v;
    }
};