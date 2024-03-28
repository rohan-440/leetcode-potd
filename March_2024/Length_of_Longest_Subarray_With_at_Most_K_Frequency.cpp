class Solution
{
public:
    int maxSubarrayLength(vector<int> &arr, int k)
    {
        map<int, int> mp;
        int l = 0;
        int len = 0;
        for (int r = 0; r < arr.size(); r++)
        {
            mp[arr[r]]++;
            while (l <= r && mp[arr[r]] > k)
            {
                mp[arr[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};