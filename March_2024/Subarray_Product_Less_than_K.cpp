class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int cnt = 0;
        int prod = 1;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            prod *= nums[r];
            while (prod >= k && l <= r)
            {
                prod /= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};