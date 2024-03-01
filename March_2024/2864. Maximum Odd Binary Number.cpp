class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int one = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                one++;
        string ans = "";
        for (int i = 0; i < one - 1; i++)
            ans.push_back('1');
        for (int i = 0; i < s.size() - one; i++)
            ans.push_back('0');
        ans.push_back('1');
        return ans;
    }
};