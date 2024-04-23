class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<int> indegree(n, 0);
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 1)
                q.push(i);
        vector<int> v;
        int left = n;
        while (!q.empty())
        {
            int size = q.size();
            left -= size;
            while (size--)
            {
                int node = q.front();
                q.pop();
                if (left == 0)
                    v.push_back(node);
                for (auto x : adj[node])
                {
                    indegree[x]--;
                    if (indegree[x] == 1)
                        q.push(x);
                }
            }
        }
        return v;
    }
};