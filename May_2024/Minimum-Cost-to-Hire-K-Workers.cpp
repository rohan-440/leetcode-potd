class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        vector<pair<double, int>> workers;
        for (int i = 0; i < wage.size(); i++)
        {
            double ratio = (wage[i] * 1.0) / quality[i];
            workers.push_back({ratio, quality[i]});
        }
        sort(workers.begin(), workers.end());
        double sum = DBL_MAX;
        double curr_sum = 0.0;
        priority_queue<int> pq;
        for (auto worker : workers)
        {
            double ratio = worker.first;
            int curr_quality = worker.second;
            pq.push(curr_quality);
            curr_sum += curr_quality;
            if (pq.size() > k)
            {
                curr_sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
            {
                sum = min(sum, curr_sum * ratio);
            }
        }

        return sum;
    }
};