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
    /*
    middle , 2nd half reverse , merge

    1   2  3
    | / | /
    5   4


    */
    ListNode *middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *m = middle(head);
        ListNode *k = reverse(m->next);
        m->next = NULL;
        ListNode *curr = head;

        while (curr != NULL && k != NULL)
        {
            ListNode *temp1 = curr->next;
            ListNode *temp2 = k->next;
            curr->next = k;
            k->next = temp1;
            curr = temp1;
            k = temp2;
        }
    }
};