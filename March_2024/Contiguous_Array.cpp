class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int cnt = 0;
        map<int, int> mp; // cnt,index
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i] == 0 ? -1 : 1;
            if (cnt == 0)
                maxi = i + 1;
            else if (mp.find(cnt) != mp.end())
            {
                maxi = max(maxi, i - mp[cnt]);
            }
            else
            {
                mp[cnt] = i;
            }
        }
        return maxi;
    }
};