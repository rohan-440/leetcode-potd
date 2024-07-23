class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        sort(nums.begin(), nums.end(), [&](int x, int y)
             {
            if(mp[x] == mp[y]) return x > y;
            return mp[x]< mp[y]; });
        return nums;
    }
};