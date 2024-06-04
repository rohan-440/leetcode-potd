class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> hm;
        int len = 0;
        bool flag = false;

        for (char ch : s)
        {
            hm[ch]++;
        }

        for (auto &el : hm)
        {
            int freq = el.second;
            if (freq % 2 == 0)
            {
                len += freq;
            }
            else
            {
                len += freq - 1;
                flag = true;
            }
        }

        return flag == true ? len + 1 : len;
    }
};