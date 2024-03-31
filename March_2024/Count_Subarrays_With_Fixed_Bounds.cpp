class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long int cnt = 0;
        int minI = -1;
        int maxI = -1;
        int l = -1;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] > maxK || nums[r] < minK)
                l = r;
            if (nums[r] == minK)
                minI = r;
            if (nums[r] == maxK)
                maxI = r;
            cnt += max(0, min(minI, maxI) - l);
        }
        return cnt;
    }
};