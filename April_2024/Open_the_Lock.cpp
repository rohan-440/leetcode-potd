class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> s;
        for (auto x : deadends)
            s.insert(x);
        queue<string> q; // string,pointer to change
        if (s.find("0000") == s.end())
            q.push("0000");
        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string node = q.front();
                q.pop();
                if (node == target)
                    return steps;
                for (int i = 0; i < 4; i++)
                {
                    string temp1 = node;
                    string temp2 = node;
                    temp1[i] += 1;
                    temp2[i] -= 1;
                    if (temp1[i] == ':')
                        temp1[i] = '0';
                    if (temp2[i] == '/')
                        temp2[i] = '9';
                    if (s.find(temp1) == s.end())
                    {
                        s.insert(temp1);
                        q.push(temp1);
                    }
                    if (s.find(temp2) == s.end())
                    {
                        s.insert(temp2);
                        q.push(temp2);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};