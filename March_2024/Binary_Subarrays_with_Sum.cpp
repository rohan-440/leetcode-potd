class Solution
{
public:
    /*


    */
    int f(vector<int> &nums, int goal)
    {
        int l = 0;
        int sum = 0;
        int cnt = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            while (l <= r && sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return f(nums, goal) - f(nums, goal - 1);
    }
};