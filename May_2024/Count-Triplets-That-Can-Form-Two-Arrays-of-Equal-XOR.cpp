class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        vector<int> prefix(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++)
        {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        unordered_map<int, int> count;
        unordered_map<int, int> total;
        int res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (count.find(prefix[i + 1]) != count.end())
            {
                res += count[prefix[i + 1]] * i - total[prefix[i + 1]];
            }
            count[prefix[i]]++;
            total[prefix[i]] += i;
        }
        return res;
    }
};