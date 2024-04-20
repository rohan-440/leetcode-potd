class Solution
{
public:
    int r = INT_MIN;
    int c = INT_MIN;
    void dfs(int x, int y, vector<vector<int>> &land)
    {
        land[x][y] = 0;
        if (r < x || c < y)
        {
            r = x;
            c = y;
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nr = x + dr[k];
            int nc = y + dc[k];
            if (nr >= 0 && nr < land.size() && nc >= 0 && nc < land[0].size() && land[nr][nc] == 1)
            {
                dfs(nr, nc, land);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> v;
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                vector<int> temp;
                if (land[i][j] == 1)
                {
                    temp.push_back(i);
                    temp.push_back(j);
                    dfs(i, j, land);
                    temp.push_back(r);
                    temp.push_back(c);
                    r = INT_MIN;
                    c = INT_MIN;
                }
                if (temp.size() > 0)
                    v.push_back(temp);
            }
        }
        return v;
    }
};