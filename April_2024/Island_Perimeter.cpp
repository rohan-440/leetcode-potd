class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0;
        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {-1, 0, 1, 0};
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int neighbour = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int r = i + dr[k];
                        int c = j + dc[k];
                        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1)
                        {
                            neighbour++;
                        }
                    }
                    perimeter += (4 - neighbour);
                }
            }
        }
        return perimeter;
    }
};