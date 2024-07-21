class Solution
{
public:
    vector<int> topo_sort(int k, vector<vector<int>> &arr)
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < arr.size(); i++)
        {
            int u = arr[i][0];
            int v = arr[i][1];
            adj[u].push_back(v);
        }
        vector<int> indegree(k + 1, 0);
        for (auto x : adj)
        {
            for (int i = 0; i < x.second.size(); i++)
            {
                indegree[x.second[i]]++;
            }
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 1; i <= k; i++)
            if (indegree[i] == 0)
                q.push(i), cnt++;
        vector<int> v;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            v.push_back(front);
            for (auto x : adj[front])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                    q.push(x), cnt++;
            }
        }
        if (cnt != k)
            return {};
        return v;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<int> topo_row = topo_sort(k, rowConditions);
        vector<int> topo_col = topo_sort(k, colConditions);
        if (topo_row.empty() || topo_col.empty())
            return {};
        vector<vector<int>> v(k, vector<int>(k, 0));
        for (int i = 0; i < topo_row.size(); i++)
        {
            for (int j = 0; j < topo_col.size(); j++)
            {
                if (topo_row[i] == topo_col[j])
                {
                    v[i][j] = topo_row[i];
                }
            }
        }
        return v;
    }
};