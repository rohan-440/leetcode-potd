class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int tot_bottle = numBottles;
        int sum = numBottles;
        while (tot_bottle >= numExchange)
        {
            int curr_bottle = tot_bottle / numExchange;
            int rem = tot_bottle % numExchange;
            sum += curr_bottle;
            tot_bottle = curr_bottle + rem;
        }
        return sum;
    }
};
