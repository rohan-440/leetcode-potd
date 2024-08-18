class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for (int i = 1; i < n; i++)
        {
            int next2 = 2 * dp[p2];
            int next3 = 3 * dp[p3];
            int next5 = 5 * dp[p5];
            dp[i] = min({next2, next3, next5});
            if (dp[i] == next2)
                p2++;
            if (dp[i] == next3)
                p3++;
            if (dp[i] == next5)
                p5++;
        }
        return dp[n - 1];
    }
};