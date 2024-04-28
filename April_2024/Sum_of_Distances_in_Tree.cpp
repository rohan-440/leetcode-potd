class Solution
{
public:
    vector<vector<int>> adj;
    void dfs0(int i, int parent, vector<int> &sum, vector<int> &cnt)
    {
        for (auto x : adj[i])
        {
            if (x == parent)
                continue;
            dfs0(x, i, sum, cnt);
            cnt[i] += cnt[x];
            sum[i] += sum[x] + cnt[x];
        }
    }

    void reroot(int i, int parent, int n, vector<int> &sum, vector<int> &cnt)
    {
        for (auto x : adj[i])
        {
            if (x == parent)
                continue;
            sum[x] = sum[i] + n - 2 * cnt[x];
            reroot(x, i, n, sum, cnt);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> sum(n, 0);
        vector<int> cnt(n, 1);
        dfs0(0, -1, sum, cnt);
        reroot(0, -1, n, sum, cnt);
        return sum;
    }
};