class Solution
{
public:
    int count_steps(int i, int j, int len)
    {
        int dis = abs(i - j);
        int wrap_dis = len - dis;
        return 1 + min(dis, wrap_dis);
    }
    int f(int i, int j, string ring, string key, vector<vector<int>> &dp)
    {
        if (j == key.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for (int k = 0; k < ring.size(); k++)
        {
            if (ring[k] == key[j])
            {
                int moves = count_steps(i, k, ring.size());
                int steps = moves + f(k, j + 1, ring, key, dp);
                res = min(res, steps);
            }
        }
        return dp[i][j] = res;
    }
    int findRotateSteps(string ring, string key)
    {
        vector<vector<int>> dp(ring.size() + 1, vector<int>(key.size() + 1, -1));
        return f(0, 0, ring, key, dp);
    }
};