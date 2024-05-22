class Solution
{
public:
    vector<vector<string>> ans;
    bool checkP(int start, int end, string s)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return 0;
        }
        return 1;
    }
    void f(int i, string s, vector<string> &temp)
    {
        if (i == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int ind = i; ind < s.size(); ind++)
        {
            if (checkP(i, ind, s))
            {
                temp.push_back(s.substr(i, ind - i + 1));
                f(ind + 1, s, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        f(0, s, temp);
        return ans;
    }
};