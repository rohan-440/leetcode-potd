class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> fq(26, 0);
        for (int i = 0; i < tasks.size(); i++)
            fq[tasks[i] - 'A']++;
        sort(fq.begin(), fq.end());
        int chunk = fq[25] - 1;
        int idle = chunk * n;
        for (int i = 24; i >= 0; i--)
        {
            idle -= min(chunk, fq[i]);
        }
        return idle < 0 ? tasks.size() : tasks.size() + idle;
    }
};