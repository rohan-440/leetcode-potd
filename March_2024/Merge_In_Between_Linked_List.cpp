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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *head = list1;
        ListNode *curr = new ListNode(0);
        ListNode *ans = curr;
        while (head != NULL && a > 0)
        {
            curr->next = new ListNode(head->val);
            curr = curr->next;
            head = head->next;
            a--;
        }
        while (list2 != NULL)
        {
            curr->next = new ListNode(list2->val);
            curr = curr->next;
            list2 = list2->next;
        }

        while (head != NULL && head->next != NULL && head->val != b)
        {
            head = head->next;
        }
        if (head->next != NULL)
            head = head->next;
        curr->next = head;
        return ans->next;
    }
};