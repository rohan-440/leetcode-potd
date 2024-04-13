class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> prevsmall(n, 0);

        stack<int> st; // stores the ind
        st.push(0);

        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                prevsmall[i] = st.top() + 1;
            }
            st.push(i);
        }

        vector<int> nextsmall(n, n);
        stack<int> st2;
        st2.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st2.empty() && heights[st2.top()] >= heights[i])
            {
                st2.pop();
            }
            if (!st2.empty())
            {
                nextsmall[i] = st2.top();
            }
            st2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, (nextsmall[i] - prevsmall[i]) * heights[i]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxArea = 0;
        vector<int> v(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    v[j] = v[j] + 1;
                }
                else
                {
                    v[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(v));
        }
        return maxArea;
    }
};