class Solution
{
public:
    void dfs(int x, int y, vector<vector<int>> &land)
    {
        land[x][y] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int r = x + dr[k];
            int c = y + dc[k];
            if (r >= 0 && r < land.size() && c >= 0 && c < land[0].size() && land[r][c] == 0)
            {
                dfs(r, c, land);
            }
        }
    }
    int regionsBySlashes(vector<string> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> land(r * 3, vector<int>(c * 3, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '/')
                {
                    land[i * 3][j * 3 + 2] = 1;
                    land[i * 3 + 1][j * 3 + 1] = 1;
                    land[i * 3 + 2][j * 3] = 1;
                }
                else if (grid[i][j] == '\\')
                {
                    land[i * 3][j * 3] = 1;
                    land[i * 3 + 1][j * 3 + 1] = 1;
                    land[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (land[i][j] == 0)
                {
                    dfs(i, j, land);
                    ans++;
                }
            }
        }
        return ans;
    }
};