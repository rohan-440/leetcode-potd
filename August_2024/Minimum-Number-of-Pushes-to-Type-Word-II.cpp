class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> mp;
        for (auto x : word)
            mp[x]++;
        priority_queue<pair<int, char>> pq;
        for (auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        int size = 0;
        int ans = 0;
        while (!pq.empty())
        {
            int cnt = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans += (cnt * ((size / 8) + 1));
            size++;
        }
        return ans;
    }
};
