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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *curr = new ListNode(-1);
        ListNode *ans = curr;
        int sum = 0;
        head = head->next;
        while (head != NULL)
        {
            sum += head->val;
            if (head->val == 0)
            {
                curr->next = new ListNode(sum);
                curr = curr->next;
                sum = 0;
            }
            head = head->next;
        }
        return ans->next;
    }
};