class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < arr1.size(); i++)
            mp[arr1[i]]++;

        for (int i = 0; i < arr2.size(); i++)
        {
            if (mp.find(arr2[i]) != mp.end())
            {
                while (mp[arr2[i]] > 0)
                {
                    v.push_back(arr2[i]);
                    mp[arr2[i]]--;
                }
            }
            mp.erase(arr2[i]);
        }

        for (auto x : mp)
        {
            while (x.second > 0)
            {
                v.push_back(x.first);
                x.second--;
            }
        }
        return v;
    }
};