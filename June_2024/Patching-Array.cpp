class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int i = 0;
        int patch = 0;
        long long int sum = 1;
        while (sum <= n)
        {
            if (i < nums.size() && nums[i] <= sum)
            {
                sum += nums[i];
                i++;
            }
            else
            {
                sum += sum;
                patch++;
            }
        }
        return patch;
    }
};