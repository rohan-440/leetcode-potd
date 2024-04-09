class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < tickets.size(); i++)
            q.push({tickets[i], i});
        while (!q.empty())
        {
            int node = q.front().first;
            int i = q.front().second;
            q.pop();
            time++;
            node -= 1;
            if (k == i && node == 0)
            {
                return time;
            }
            // cout<<node<<endl;
            if (node > 0)
                q.push({node, i});
        }
        return time;
    }
};