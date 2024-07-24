class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;

        auto getMappedValue = [&](int number)
        {
            if (number == 0)
                return mapping[0];
            int mapped = 0, place = 1;
            while (number > 0)
            {
                mapped += mapping[number % 10] * place;
                place *= 10;
                number /= 10;
            }
            return mapped;
        };

        sort(nums.begin(), nums.end(), [&](int x, int y)
             {
            int mappedX = getMappedValue(x);
            int mappedY = getMappedValue(y);
            if (mappedX == mappedY) return mp[x] < mp[y];
            return mappedX < mappedY; });

        return nums;
    }
};
