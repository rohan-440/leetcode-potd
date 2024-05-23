class Solution
{
public:
    bool check(int x, int k, vector<int> &v)
    {
        for (auto i : v)
        {
            if (abs(i - x) == k)
                return 0;
        }
        return 1;
    }
    void f(int i, int k, vector<int> &nums, vector<int> &temp, int &ans)
    {
        if (i >= nums.size())
        {
            ans++;
            return;
        }
        if (check(nums[i], k, temp))
        {
            temp.push_back(nums[i]);
            f(i + 1, k, nums, temp, ans);
            temp.pop_back();
        }
        f(i + 1, k, nums, temp, ans);
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int ans = -1;
        vector<int> temp;
        f(0, k, nums, temp, ans);
        return ans;
    }
};