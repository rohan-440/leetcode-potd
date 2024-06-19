class Solution
{
public:
    bool make(int day, int m, int k, vector<int> &bloomDay)
    {
        int adj = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                adj++;
            }
            else
            {
                adj = 0;
            }
            if (adj == k)
                m--, adj = 0;
        }
        return m <= 0 ? 1 : 0;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int minDay = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (make(mid, m, k, bloomDay))
            {
                minDay = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return minDay;
    }
};