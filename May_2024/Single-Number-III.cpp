class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int Xor = 0;
        for (int i = 0; i < nums.size(); i++)
            Xor ^= nums[i];
        int mask = 1;
        while (!(mask & Xor))
            mask <<= 1;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & mask)
            {
                a ^= nums[i];
            }
            else
            {
                b ^= nums[i];
            }
        }
        return {a, b};
    }
};