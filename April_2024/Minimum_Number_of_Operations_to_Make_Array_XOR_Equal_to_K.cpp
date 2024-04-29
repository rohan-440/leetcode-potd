class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int Xor = 0;
        for (int i = 0; i < nums.size(); i++)
            Xor ^= nums[i];
        int op = 0;
        while (Xor > 0 || k > 0)
        {
            int getxor = Xor & 1;
            int getk = k & 1;
            if (getxor != getk)
                op++;
            Xor >>= 1;
            k >>= 1;
        }
        return op;
    }
};