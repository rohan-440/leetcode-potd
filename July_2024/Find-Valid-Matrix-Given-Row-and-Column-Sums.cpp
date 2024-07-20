class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        vector<vector<int>> v(rowSum.size(), vector<int>(colSum.size(), 0));
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[0].size(); j++)
            {
                int mini = min(rowSum[i], colSum[j]);
                v[i][j] = mini;
                rowSum[i] -= mini;
                colSum[j] -= mini;
                // cout<<v[i][j]<<" ";
            }
            // cout<<endl;
        }

        return v;
    }
};