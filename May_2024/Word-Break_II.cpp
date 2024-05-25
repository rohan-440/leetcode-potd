class Solution
{
public:
    vector<string> v;
    void f(int i, string &s, unordered_set<string> &set, string &temp)
    {
        if (i >= s.size())
        {
            v.push_back(temp);
            return;
        }
        for (int end = i + 1; end <= s.size(); end++)
        {
            string sub = s.substr(i, end - i);
            if (set.find(sub) != set.end())
            {
                string prev = temp.size() == 0 ? sub : (temp + " " + sub);
                cout << sub << endl;
                f(end, s, set, prev);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        v.clear();
        // unordered_set<string>set;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        string temp = "";
        f(0, s, set, temp);
        return v;
    }
};