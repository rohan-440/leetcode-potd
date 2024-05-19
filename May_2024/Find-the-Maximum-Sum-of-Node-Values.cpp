class Solution
{
public:
    int n;
    vector<vector<long long>> dp;

    long long solve(int i, int j, vector<int> &nums, int k)
    {
        if (i == n)
            return j == 0 ? 0 : -INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long notake = nums[i] + solve(i + 1, j, nums, k);
        long long take = (nums[i] ^ k) + solve(i + 1, (j + 1) % 2, nums, k);

        return dp[i][j] = max(take, notake);
    }
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {

        n = nums.size();
        dp.resize(n, vector<long long>(2, -1));
        return solve(0, 0, nums, k);
    }
};