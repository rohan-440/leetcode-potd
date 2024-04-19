class Solution
{
public:
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        grid[x][y] = '0';
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int r = x + dr[k];
            int c = y + dc[k];
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1')
                dfs(r, c, grid);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int land = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    land++;
                }
            }
        }
        return land;
    }
};