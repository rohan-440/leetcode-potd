class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int window_size = accumulate(nums.begin(), nums.end(), 0);
        vector<int> v(nums.begin(), nums.end());
        int zero = 0;
        for (int i = 0; i < window_size; i++)
        {
            v.push_back(nums[i]);
            if (nums[i] == 0)
                zero++;
        }
        int min_zero = zero;
        int r = window_size;
        for (int l = 0; l < nums.size(); l++)
        {
            if (v[l] == 0)
                zero--;
            if (v[r] == 0)
                zero++;
            r++;
            min_zero = min(min_zero, zero);
        }
        return min_zero;
    }
};