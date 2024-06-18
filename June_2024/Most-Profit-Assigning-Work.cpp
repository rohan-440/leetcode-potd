class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<vector<int>> v;
        for (int i = 0; i < profit.size(); i++)
            v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end());
        int maxi = 0;
        for (int i = 0; i < worker.size(); i++)
        {
            int profits = 0;
            for (int j = profit.size() - 1; j >= 0; j--)
            {
                if (difficulty[j] <= worker[i])
                {
                    profits = max(profits, profit[j]);
                }
            }
            maxi += profits;
        }
        return maxi;
    }
};