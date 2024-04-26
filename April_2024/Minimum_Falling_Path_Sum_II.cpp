class Solution
{
public:
    int f(int i, int prev, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (i >= arr.size())
            return 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        int take = 1e9;
        for (int k = 0; k < arr.size(); k++)
        {
            if (prev != k)
            {
                take = min(take, arr[i][k] + f(i + 1, k, arr, dp));
            }
        }
        return dp[i][prev] = take;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int mini = 1e9;
        vector<vector<int>> dp(210, vector<int>(210, -1));
        for (int i = 0; i < grid.size(); i++)
        {
            mini = min(mini, grid[0][i] + f(1, i, grid, dp));
        }
        return mini;
        // return f(0,-1,grid,dp);
    }
};