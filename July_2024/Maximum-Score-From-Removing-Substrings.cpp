class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        if (x < y)
        {
            reverse(s.begin(), s.end());
            return maximumGain(s, y, x);
        }
        stack<int> stAB;
        stack<int> stBA;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!stAB.empty() && stAB.top() == 'a' && s[i] == 'b')
            {
                while (!stAB.empty() && stAB.top() == 'a' && s[i] == 'b')
                {
                    stAB.pop();
                    sum += x;
                }
            }
            else
            {
                stAB.push(s[i]);
            }
        }
        while (!stAB.empty())
        {
            char ch = stAB.top();
            stAB.pop();
            if (!stBA.empty() && stBA.top() == 'a' && ch == 'b')
            {
                while (!stBA.empty() && stBA.top() == 'a' && ch == 'b')
                {
                    stBA.pop();
                    sum += y;
                }
            }
            else
            {
                stBA.push(ch);
            }
        }
        return sum;
    }
};