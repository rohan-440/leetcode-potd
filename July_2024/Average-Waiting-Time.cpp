class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        long long int sum = 0;
        int end = 0;
        for (int i = 0; i < customers.size() - 1; i++)
        {
            int finish_order = max(end, customers[i][0]) + customers[i][1];
            sum += finish_order - customers[i][0];
            end = max(finish_order, customers[i + 1][0]);
        }
        sum += ((max(customers[customers.size() - 1][0], end) + customers[customers.size() - 1][1]) - customers[customers.size() - 1][0]);
        return double(sum * 1.0) / (customers.size() * 1.0);
    }
};