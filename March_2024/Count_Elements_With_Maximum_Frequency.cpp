class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        int maxi = 0;
        for (auto x : mp)
        {
            maxi = max(maxi, x.second);
        }
        int maxiSum = 0;
        for (auto x : mp)
        {
            if (x.second == maxi)
            {
                maxiSum += x.second;
            }
        }
        return maxiSum;
    }
};