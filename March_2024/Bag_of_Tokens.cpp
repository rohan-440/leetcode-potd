class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int maxi = 0;
        int curr = 0;
        int l = 0;
        int r = tokens.size() - 1;
        while (l <= r)
        {
            if (power >= tokens[l])
            {
                curr++;
                power -= tokens[l];
                maxi = max(maxi, curr);
                l++;
            }
            else
            {
                maxi = max(maxi, curr);
                if (curr > 0)
                {
                    curr--;
                    power += tokens[r];
                }
                r--;
            }
        }
        return maxi;
    }
};