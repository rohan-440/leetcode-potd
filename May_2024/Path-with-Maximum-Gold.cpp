class Solution
{
public:
    int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[x][y] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int path = 0;
        for (int i = 0; i < 4; i++)
        {
            int r = x + dr[i];
            int c = y + dc[i];
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] != 0 && vis[r][c] == 0)
            {
                path = max(path, dfs(r, c, grid, vis));
            }
        }
        vis[x][y] = 0;
        return path + grid[x][y];
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int maxi = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                {
                    vector<vector<int>> vis(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
                    maxi = max(maxi, dfs(i, j, grid, vis));
                }
            }
        }
        return maxi;
    }
};