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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == nullptr)
            return head->next;
        ListNode *slow = head;
        ListNode *curr = slow;
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return curr;
    }
};