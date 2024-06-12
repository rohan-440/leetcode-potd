class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        int l = 0;
        for (auto x : mp)
        {
            while (x.second > 0)
            {
                nums[l] = x.first;
                x.second--;
                l++;
            }
        }
        // return nums;
    }
};