class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            vector<int> vis(n, 0);
            for (auto x : adj[i])
            {
                vis[x] = 1;
                q.push(x);
            }
            vector<int> temp;

            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                temp.push_back(front);

                for (auto x : adj[front])
                    if (vis[x] == 0)
                    {
                        q.push(x);
                        vis[x] = 1;
                    }
            }
            sort(temp.begin(), temp.end());
            v.push_back(temp);
        }
        return v;
    }
};