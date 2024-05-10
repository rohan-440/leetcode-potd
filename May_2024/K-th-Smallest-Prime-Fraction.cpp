class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>> pq;

        // Push fractions into priority queue
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                double fraction = (double)arr[i] / arr[j];
                pq.push({fraction, {arr[i], arr[j]}});

                // Pop the top element if size exceeds k
                if (pq.size() >= k + 1)
                {
                    pq.pop();
                }
            }
        }

        // The top of the priority queue now holds the kth smallest fraction
        vector<int> result;
        result.push_back(pq.top().second.first);
        result.push_back(pq.top().second.second);
        return result;
    }
};
