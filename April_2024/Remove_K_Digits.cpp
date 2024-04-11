class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<int> st;
        for (int i = 0; i < num.size(); i++)
        {
            while (!st.empty() && num[st.top()] > num[i] && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(i);
        }
        while (k-- > 0)
            st.pop();
        if (st.empty())
            return "0";
        string s = "";
        while (!st.empty())
        {
            s.push_back(num[st.top()]);
            st.pop();
        }
        reverse(s.begin(), s.end());

        int i = 0;
        while (s[i] == '0')
            i++;
        if (i == s.size())
            return "0";
        return s.substr(i);
    }
};