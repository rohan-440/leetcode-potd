class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); i++)
        {
            max_distance = max(max_distance, abs(arrays[i][arrays[i].size() - 1] - min_val));
            max_distance = max(max_distance, abs(max_val - arrays[i][0]));

            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i][arrays[i].size() - 1]);
        }

        return max_distance;
    }
};
