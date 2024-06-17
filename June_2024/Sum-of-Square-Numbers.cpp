class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; a++)
        {
            long b_squared = c - a * a;
            long b = sqrt(b_squared);
            if (b * b == b_squared)
            {
                return true;
            }
        }
        return false;
    }
};