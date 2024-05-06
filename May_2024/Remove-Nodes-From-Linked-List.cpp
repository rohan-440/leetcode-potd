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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head != NULL)
        {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *curr = reverse(head);
        ListNode *node = new ListNode(curr->val);
        ListNode *ans = node;
        while (curr != NULL)
        {
            if (curr->val >= node->val)
            {
                node->next = new ListNode(curr->val);
                node = node->next;
            }
            curr = curr->next;
        }
        return reverse(ans->next);
    }
};