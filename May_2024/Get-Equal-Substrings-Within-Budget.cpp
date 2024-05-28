class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        // vector<int>v;
        // for(int i = 0 ; i < s.size(); i++){
        //     v.push_back(abs(s[i]-t[i]));
        // }
        int len = 0;
        int l = 0;
        int sum = 0;
        for (int r = 0; r < s.size(); r++)
        {
            sum += abs(s[r] - t[r]);
            while (sum > maxCost)
            {
                sum -= abs(s[l] - t[l]);
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};