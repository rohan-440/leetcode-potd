class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int maxi = 0;
        int satisfied = 0;
        for (int i = 0; i < customers.size(); i++)
            if (grumpy[i] == 0)
                satisfied += customers[i];
        int additional = 0;
        for (int i = 0; i < minutes; i++)
            if (grumpy[i] == 1)
                additional += customers[i];
        maxi = satisfied + additional;
        for (int i = minutes; i < customers.size(); i++)
        {
            if (grumpy[i] == 1)
                additional += customers[i];
            if (grumpy[i - minutes] == 1)
                additional -= customers[i - minutes];
            maxi = max(maxi, satisfied + additional);
        }

        return maxi;
    }
};