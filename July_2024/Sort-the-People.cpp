class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<int> ind(names.size());
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int x, int y)
             { return heights[x] > heights[y]; });
        vector<string> ans;
        for (int i = 0; i < ind.size(); i++)
        {
            ans.push_back(names[ind[i]]);
        }
        return ans;
    }
};