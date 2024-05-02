class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(-nums[i]) != s.end() && maxi < nums[i])
            {
                maxi = nums[i];
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};