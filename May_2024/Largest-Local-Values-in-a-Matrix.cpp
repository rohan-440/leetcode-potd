class Solution
{
public:
    int dfs(int x, int y, vector<vector<int>> &grid)
    {
        int num = INT_MIN;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                num = max(num, grid[i][j]);
            }
        }
        return num;
    }
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        vector<vector<int>> maxLocal(grid.size() - 2, vector<int>(grid.size() - 2, 0));
        for (int i = 0; i < maxLocal.size(); i++)
        {
            for (int j = 0; j < maxLocal.size(); j++)
            {
                maxLocal[i][j] = dfs(i, j, grid);
            }
        }
        return maxLocal;
    }
};