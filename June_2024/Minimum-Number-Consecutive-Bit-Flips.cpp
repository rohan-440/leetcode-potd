class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int flip = 0;
        int count = 0;
        vector<int> curr(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            flip += curr[i];
            if (flip % 2 == nums[i])
            {
                if (i + k > nums.size())
                    return -1;
                curr[i] += 1;
                curr[i + k] -= 1;
                flip++;
                count++;
            }
        }
        return count;
    }
};
