class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (end < intervals[i][0])
            {
                v.push_back({s, end});
                s = intervals[i][0];
            }
            end = max(end, intervals[i][1]);
        }
        v.push_back({s, end});
        return v;
    }
};