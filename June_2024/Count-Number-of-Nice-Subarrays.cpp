class Solution
{
public:
    int f(vector<int> &nums, int k)
    {
        int l = 0;
        int cnt = 0;
        int numOdd = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] % 2 != 0)
                numOdd++;
            while (l <= r && numOdd > k)
            {
                if (nums[l] % 2 != 0)
                    numOdd--;
                l++;
            }
            // if(numOdd == k)
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return f(nums, k) - f(nums, k - 1);
    }
};