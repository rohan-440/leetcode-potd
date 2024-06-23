class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int len = 0;
        multiset<int> mset;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            mset.insert(nums[r]);
            while (*mset.rbegin() - *mset.begin() > limit)
            {
                mset.erase(mset.find(nums[l]));
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};