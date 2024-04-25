class Solution
{
public:
    int f(int i, int prev, string &s, int k, vector<vector<int>> &dp)
    {
        if (i >= s.size())
            return 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        int take = 0;
        int ch = s[i] - 'a' + 1;
        if (prev == 0 || (abs(ch - prev) <= k))
        {
            take = 1 + f(i + 1, ch, s, k, dp);
        }
        int nottake = f(i + 1, prev, s, k, dp);
        return dp[i][prev] = max(take, nottake);
    }
    int longestIdealString(string s, int k)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(27, -1));
        return f(0, 0, s, k, dp);
    }
};