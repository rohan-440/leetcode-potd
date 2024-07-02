class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp1, mp2;
        for (auto x : nums1)
            mp1[x]++;
        for (auto x : nums2)
            mp2[x]++;
        vector<int> v;
        for (auto x : mp1)
        {
            int mini = min(x.second, mp2[x.first]);
            if (mini > 0)
            {
                for (int i = 0; i < mini; i++)
                    v.push_back(x.first);
            }
        }
        return v;
    }
};