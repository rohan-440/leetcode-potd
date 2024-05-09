class Solution
{
public:
    /*
    1 1 1 1
    1-0 = 1
    0
    1-1 = 0

    */
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long cnt = 0;
        sort(happiness.rbegin(), happiness.rend());
        for (int i = 0; i < happiness.size(); i++)
        {
            if (k > 0)
            {
                if ((happiness[i] - i) > 0)
                {
                    cnt += happiness[i] - i;
                }
                k--;
            }
        }
        return cnt;
    }
};