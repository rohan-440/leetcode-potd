class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return 0;
        unordered_map<char, char> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
            else if (mp[s[i]] != t[i])
                return 0;
        }
        unordered_set<char> st;
        for (auto x : mp)
        {
            if (st.find(x.second) != st.end())
                return 0;
            st.insert(x.second);
        }
        return 1;
    }
};