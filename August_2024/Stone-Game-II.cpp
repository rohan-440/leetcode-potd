class Solution
{
public:
    int f(int i, int person, int m, vector<int> &piles, vector<vector<vector<int>>> &dp)
    {
        int n = piles.size();
        if (i >= piles.size())
            return 0;
        if (dp[i][person][m] != -1)
            return dp[i][person][m];
        int result = person == 1 ? -1 : INT_MAX;
        int stones = 0;
        for (int x = 1; x <= min(2 * m, n - i); x++)
        {
            stones += piles[i + x - 1];
            if (person == 1)
            {
                result = max(result, stones + f(i + x, 0, max(m, x), piles, dp));
            }
            else
            {
                result = min(result, f(i + x, 1, max(m, x), piles, dp));
            }
        }
        return dp[i][person][m] = result;
    }
    int stoneGameII(vector<int> &piles)
    {
        vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(3, vector<int>(101, -1)));
        return f(0, 1, 1, piles, dp);
    }
};