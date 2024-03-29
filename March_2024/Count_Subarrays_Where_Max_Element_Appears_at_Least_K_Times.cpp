class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxi = *max_element(nums.begin(), nums.end());
        long long count = 0;
        int l = 0;
        int fq = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == maxi)
                fq++;
            while (fq >= k && l <= r)
            {
                count += (nums.size() - r);
                if (nums[l] == maxi)
                    fq--;
                l++;
            }
        }
        return count;
    }
};