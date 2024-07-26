class Solution
{
public:
    void bfs(int src, vector<vector<pair<int, int>>> &adj, vector<int> &dis)
    {
        queue<pair<int, int>> q;
        q.push({src, 0});
        dis[src] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            for (auto x : adj[node])
            {
                if (x.second + cost < dis[x.first])
                {
                    dis[x.first] = x.second + cost;
                    q.push({x.first, dis[x.first]});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        int node = -1;
        int neighbour = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            vector<int> dis(n, 1e9);
            bfs(i, adj, dis);
            int cnt = 0;
            for (int k = 0; k < dis.size(); k++)
            {
                if (i != k && dis[k] <= distanceThreshold)
                    cnt++;
            }
            if (neighbour > cnt)
            {
                neighbour = cnt;
                node = i;
            }
            if (neighbour == cnt)
            {
                node = max(node, i);
            }
        }

        return node;
    }
};