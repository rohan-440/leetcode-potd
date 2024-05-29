class Solution
{
public:
    int numSteps(string s)
    {
        int step = 0;
        while (s != "1")
        {
            if (s.back() == '1')
            { // odd
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1')
                {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0)
                {
                    s[i] = '1';
                }
                else
                {
                    s = '1' + s;
                }
            }
            else
            { // even
                s.pop_back();
            }
            step++;
        }
        return step;
    }
};