class Solution
{
public:
    string customSortString(string order, string s)
    {
        map<char, int> mp;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        for (int i = 0; i < order.size(); i++)
        {
            if (mp.find(order[i]) != mp.end())
            {
                for (int j = 0; j < mp[order[i]]; j++)
                    ans.push_back(order[i]);
                mp.erase(order[i]);
            }
        }

        for (auto x : mp)
        {
            for (int j = 0; j < x.second; j++)
                ans.push_back(x.first);
        }
        return ans;
    }
};