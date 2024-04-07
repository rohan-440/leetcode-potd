class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> st;
        stack<int> star;
        for (int x = 0; x < s.size(); x++)
        {
            if (s[x] == ')')
            {
                if (st.empty())
                {
                    if (!star.empty())
                        star.pop();
                    else
                        return 0;
                }
                else
                    st.pop();
            }
            else if (s[x] == '*')
                star.push(x);
            else if (s[x] == '(')
                st.push(x);
        }
        while (!st.empty())
        {
            if (star.empty())
                return 0;
            if (st.top() > star.top())
                return 0;
            star.pop();
            st.pop();
        }
        return 1;
    }
};