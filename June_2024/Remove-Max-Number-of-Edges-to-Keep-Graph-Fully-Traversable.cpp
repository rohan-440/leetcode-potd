class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    int comp;
    DSU(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
        comp = n;
    }
    int find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v)
    {
        int a = find(u);
        int b = find(v);
        if (a == b)
            return;
        if (size[a] < size[b])
        {
            size[b] += size[a];
            parent[a] = b;
        }
        else
        {
            size[a] += size[b];
            parent[b] = a;
        }
        comp--;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU alice(n);
        DSU bob(n);
        sort(edges.rbegin(), edges.rend());
        int edge = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if (type == 3)
            {
                bool addedge = false;
                if (alice.find(u) != alice.find(v))
                {
                    alice.Union(u, v);
                    addedge = true;
                }
                if (bob.find(u) != bob.find(v))
                {
                    bob.Union(u, v);
                    addedge = true;
                }
                if (addedge == true)
                {
                    edge++;
                }
            }
            else if (type == 2)
            {
                if (bob.find(u) != bob.find(v))
                {
                    bob.Union(u, v);
                    edge++;
                }
            }
            else
            {
                if (alice.find(u) != alice.find(v))
                {
                    alice.Union(u, v);
                    edge++;
                }
            }
        }
        if (alice.comp == 1 && bob.comp == 1)
            return edges.size() - edge;
        cout << alice.comp << " " << bob.comp << endl;
        return -1;
    }
};