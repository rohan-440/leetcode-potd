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
class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *curr = reverse(head);
        ListNode *node = new ListNode(-1);
        ListNode *v = node;
        int carry = 0;
        while (curr != NULL)
        {
            int mul = curr->val * 2 + carry;
            if (mul > 9)
            {
                node->next = new ListNode(mul % 10);
                carry = mul / 10;
            }
            else
            {
                node->next = new ListNode(mul);
                carry = 0;
            }
            curr = curr->next;
            node = node->next;
        }
        if (carry > 0)
        {
            node->next = new ListNode(carry);
            node = node->next;
        }
        ListNode *ans = reverse(v->next);
        return ans;
    }
};