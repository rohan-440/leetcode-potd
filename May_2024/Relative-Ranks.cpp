class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<int> v = score;
        vector<string> ans;
        sort(v.rbegin(), v.rend());
        map<int, string> mp;
        mp[v[0]] = "Gold Medal";
        if (v.size() == 1)
            return {mp[v[0]]};
        mp[v[1]] = "Silver Medal";
        if (v.size() == 2)
        {
            if (score[0] < score[1])
                return {mp[v[1]], mp[v[0]]};
            else
                return {mp[v[0]], mp[v[1]]};
        }
        mp[v[2]] = "Bronze Medal";
        for (int i = 3; i < v.size(); i++)
        {
            mp[v[i]] = to_string(i + 1);
        }

        for (int i = 0; i < score.size(); i++)
        {
            ans.push_back(mp[score[i]]);
        }
        return ans;
    }
};