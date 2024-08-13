class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n);

        for (auto edge : edges)
        {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<pair<int, int>> dist(n, {1e9, 1e9});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = {0, 1e9};
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [weight, node] = pq.top();
            pq.pop();

            if (weight > dist[node].second)
            {
                continue;
            }

            int newTime = weight + time;

            int temp = weight / change;
            if (temp % 2 == 1)
            {
                newTime = (temp + 1) * change + time;
            }

            for (auto i : adj[node])
            {
                if (dist[i].first > newTime)
                {
                    dist[i].second = dist[i].first;
                    dist[i].first = newTime;
                    pq.push({dist[i].first, i});
                }

                else if (dist[i].first == newTime)
                {
                    continue;
                }
                else if (dist[i].second > newTime)
                {
                    dist[i].second = newTime;
                    pq.push({dist[i].second, i});
                }
            }
        }
        return dist[n - 1].second;
    }
};