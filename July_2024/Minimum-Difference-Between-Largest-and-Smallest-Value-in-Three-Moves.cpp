class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        if (nums.size() < 5)
            return 0;
        sort(nums.begin(), nums.end());
        int mini = nums[nums.size() - 1] - nums[0];
        for (int l = 0; l < 4; l++)
        {
            int r = 3 - l;
            mini = min(nums[nums.size() - 1 - r] - nums[l], mini);
        }
        return mini;
    }
};