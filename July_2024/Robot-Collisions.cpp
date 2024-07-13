class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &health, string directions)
    {
        int n = positions.size();
        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);
        stack<int> st;
        sort(ind.begin(), ind.end(), [&](auto x, auto y) -> bool
             { return positions[x] < positions[y]; });
        for (int curr = 0; curr < ind.size(); curr++)
        {
            int i = ind[curr];
            if (directions[i] == 'R')
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && health[i] > 0)
                {
                    int top = st.top();
                    st.pop();
                    if (health[top] > health[i])
                    {
                        health[top]--;
                        health[i] = 0;
                        st.push(top);
                    }
                    else if (health[top] < health[i])
                    {
                        health[i]--;
                        health[top] = 0;
                    }
                    else
                    {
                        health[i] = 0;
                        health[top] = 0;
                    }
                }
            }
        }
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (health[i] > 0)
                v.push_back(health[i]);
        return v;
    }
};