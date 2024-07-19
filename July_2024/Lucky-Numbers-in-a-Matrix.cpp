class Solution
{
public:
    int mini_row(vector<int> &arr)
    {
        return *min_element(arr.begin(), arr.end());
    }
    int maxi_col(int c, vector<vector<int>> arr)
    {
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++)
            maxi = max(maxi, arr[i][c]);
        return maxi;
    }
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> v;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int mini = mini_row(matrix[i]);
                int maxi = maxi_col(j, matrix);
                if (mini == matrix[i][j] && maxi == matrix[i][j])
                    v.push_back(mini);
            }
        }
        return v;
    }
};