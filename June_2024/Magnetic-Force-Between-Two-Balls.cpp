class Solution
{
public:
    bool check(int mid, vector<int> &position, int m)
    {
        int m_placed = 1;
        int last_placed = position[0];
        for (int i = 0; i < position.size(); i++)
        {
            if ((position[i] - last_placed) >= mid)
            {
                m_placed++;
                last_placed = position[i];
                if (m == m_placed)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int low = 0;
        int high = position[position.size() - 1];
        int minDis = position[position.size() - 1];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, position, m))
            {
                minDis = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return minDis;
    }
};