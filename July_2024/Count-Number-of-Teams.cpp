class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int cnt = 0;
        int n = rating.size();
        for (int i = 0; i < n; i++)
        {
            int l_small = 0;
            int l_big = 0;
            int r_small = 0;
            int r_big = 0;
            for (int l = 0; l < i; l++)
            {
                if (rating[i] > rating[l])
                    l_small++;
                if (rating[i] < rating[l])
                    l_big++;
            }
            for (int r = i + 1; r < n; r++)
            {
                if (rating[i] > rating[r])
                    r_small++;
                if (rating[i] < rating[r])
                    r_big++;
            }
            cnt += (l_small * r_big);
            cnt += (l_big * r_small);
        }
        return cnt;
    }
};