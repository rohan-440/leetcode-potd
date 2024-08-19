class Solution
{
public:
    int f(int clip, int curr, int n, vector<vector<int>> &dp)
    {
        if (curr == n)
            return 0;
        if (curr > n)
            return 1e9;
        if (dp[clip][curr] != -1)
            return dp[clip][curr];
        int copy_paste = 2 + f(curr, curr + curr, n, dp);
        int paste = 1 + f(clip, curr + clip, n, dp);
        return dp[clip][curr] = min(copy_paste, paste);
    }
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return 1 + f(1, 1, n, dp);
    }
};