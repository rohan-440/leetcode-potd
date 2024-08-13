class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<long long>> dis(26, vector<long long>(26, LONG_MAX));

        for (int i = 0; i < original.size(); i++)
        {
            int u = original[i] - 'a';
            char v = changed[i] - 'a';
            long long wt = cost[i];
            dis[u][v] = min(dis[u][v], wt);
        }

        for (int via = 0; via < 26; via++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (dis[i][via] != LONG_MAX && dis[via][j] != LONG_MAX)
                    {
                        dis[i][j] = min(dis[i][j], (dis[i][via] + dis[via][j]));
                    }
                }
            }
        }

        int i = 0, j = 0, n = source.length();
        long long ans = 0;
        while (i < n)
        {
            if (source[i] != target[j])
            {
                int s = source[i] - 'a';
                int d = target[j] - 'a';
                long long c = dis[s][d];
                if (c == LONG_MAX)
                    return -1;
                ans += c;
            }
            i++;
            j++;
        }
        return ans;
    }
};
