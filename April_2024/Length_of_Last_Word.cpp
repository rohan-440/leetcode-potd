class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.size() == 1)
            return 1;
        int i = s.size() - 1;
        while (s[i] == ' ' && i >= 0)
        {
            i--;
        }
        int k = i;
        cout << k << endl;
        for (int j = k; j >= 0; j--)
        {
            if (s[j] == ' ')
                return k - j;
        }
        return k + 1;
    }
};