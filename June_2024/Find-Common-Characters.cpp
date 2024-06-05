class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> ans(26, INT_MAX);
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> v(26, 0);
            for (int j = 0; j < words[i].size(); j++)
            {
                v[words[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; j++)
            {
                ans[j] = min(ans[j], v[j]);
            }
        }
        vector<string> temp;
        for (int i = 0; i < 26; i++)
        {
            while (ans[i] > 0)
            {
                string s(1, 'a' + i);
                temp.push_back(s);
                ans[i]--;
            }
        }

        return temp;
    }
};