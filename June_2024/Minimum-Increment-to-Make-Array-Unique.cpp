class Solution
{
public:
    /*
    [3,2,1,2,1,7]

    [1,1,2,2,3,7]
    last = 2
    curr = 2
    moves = 2
    */
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int move = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            // cout<<"prev : "<<nums[i]<<" ";
            if (nums[i - 1] >= nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[i - 1] + 1;
                // cout<<"now : "<<nums[i]<<" ";
                move += nums[i] - temp;
            }
            //    cout<<endl;
        }
        return move;
    }
};