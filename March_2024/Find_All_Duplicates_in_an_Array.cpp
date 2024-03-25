class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // Negative marking
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            int ind = abs(nums[i]) - 1;
            if (nums[ind] < 0)
            {
                v.push_back(ind + 1);
            }
            else
            {
                nums[ind] *= (-1);
            }
        }
        return v;
    }
};