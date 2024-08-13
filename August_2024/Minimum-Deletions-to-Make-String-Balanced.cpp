class Solution
{
public:
    int minimumDeletions(string s)
    {
        int cntB = 0;
        int del = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'b')
                cntB++;
            else if (cntB > 0 && s[i] == 'a')
            {
                cntB--;
                del++;
            }
        }
        return del;
    }
};