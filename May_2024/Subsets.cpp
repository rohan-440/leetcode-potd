class Solution
{
public:
    vector<vector<int>> v;
    void f(int i, vector<int> &nums, vector<int> &temp)
    {
        if (i >= nums.size())
        {
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        f(i + 1, nums, temp);
        temp.pop_back();
        f(i + 1, nums, temp);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        f(0, nums, temp);
        return v;
    }
};