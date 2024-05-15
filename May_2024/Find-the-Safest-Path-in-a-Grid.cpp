class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        vector<vector<int>> dis(grid.size(), vector<int>(grid.size(), 1e9));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({0, {i, j}});
                    dis[i][j] = 0;
                }
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for (int x = 0; x < 4; x++)
            {
                int nr = r + dr[x];
                int nc = c + dc[x];
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid.size())
                {
                    if (dis[nr][nc] > 1 + d)
                    {
                        dis[nr][nc] = d + 1;
                        q.push({d + 1, {nr, nc}});
                    }
                }
            }
        }

        for (int i = 0; i < dis.size(); i++)
        {
            for (int j = 0; j < dis.size(); j++)
            {
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }

        vector<vector<int>> maxdis(grid.size(), vector<int>(grid.size(), -1));
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        maxHeap.push({dis[0][0], {0, 0}});
        maxdis[0][0] = 0;
        while (!maxHeap.empty())
        {
            int d = maxHeap.top().first;
            int r = maxHeap.top().second.first;
            int c = maxHeap.top().second.second;
            maxHeap.pop();
            if (r == grid.size() - 1 && c == grid.size() - 1)
                return d;
            for (int x = 0; x < 4; x++)
            {
                int nr = r + dr[x];
                int nc = c + dc[x];
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid.size())
                {
                    int mindis = min(d, dis[nr][nc]);
                    if (mindis > maxdis[nr][nc])
                    {
                        maxdis[nr][nc] = mindis;
                        maxHeap.push({mindis, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};