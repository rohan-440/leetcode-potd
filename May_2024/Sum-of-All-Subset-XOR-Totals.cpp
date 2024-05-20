class Solution
{
public:
    int f(int i, int x, vector<int> &nums)
    {
        if (i >= nums.size())
            return 0;
        int notake = f(i + 1, x, nums);
        int take = (nums[i] ^ x) + f(i + 1, x ^ nums[i], nums);
        return notake + take;
    }
    int subsetXORSum(vector<int> &nums)
    {
        return f(0, 0, nums);
    }
};