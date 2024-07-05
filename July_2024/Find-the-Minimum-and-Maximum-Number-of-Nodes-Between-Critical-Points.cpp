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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev = head;
        ListNode *curr = head->next;
        if (curr->next == NULL)
            return {-1, -1};
        ListNode *far = head->next->next;
        vector<int> points;
        int i = 1;
        while (far != NULL)
        {
            if (curr->val > prev->val && curr->val > far->val)
            {
                points.push_back(i);
            }
            else if (curr->val < prev->val && curr->val < far->val)
            {
                points.push_back(i);
            }
            prev = prev->next;
            curr = curr->next;
            far = far->next;
            i++;
        }
        int mini = INT_MAX;
        for (int i = 1; i < points.size(); i++)
        {
            mini = min(mini, points[i] - points[i - 1]);
            cout << points[i] << " ";
        }
        if (mini == INT_MAX)
            return {-1, -1};
        return {mini, points[points.size() - 1] - points[0]};
    }
};