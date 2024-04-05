class Solution
{
public:
    string makeGood(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (ans.size() == 0)
                ans.push_back(s[i]);
            else
            {
                if (abs(s[i] - ans.back()) == 32)
                    ans.pop_back();
                else
                    ans.push_back(s[i]);
            }
        }
        return ans;
    }
};