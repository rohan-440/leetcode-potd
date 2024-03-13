class Solution
{
public:
    int pivotInteger(int n)
    {
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= n; i++)
            v.push_back(i + v.back());
        int sum = v[n];
        for (int i = 1; i <= n; i++)
            if ((2 * v[i]) - i == sum)
                return i;
        return -1;
    }
};