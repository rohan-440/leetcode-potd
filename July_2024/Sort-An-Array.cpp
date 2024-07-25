class Solution
{
public:
    int partition(int l, int r, vector<int> &nums)
    {
        int pivot = nums[l];
        int low = l + 1;
        int high = r;

        while (low <= high)
        {
            while (low <= high && nums[low] < pivot)
                low++;
            while (low <= high && nums[high] > pivot)
                high--;
            if (low <= high)
            {
                swap(nums[low], nums[high]);
                low++;
                high--;
            }
        }
        if (low > high)
            swap(nums[l], nums[high]);
        return high;
    }

    void quicksort(int l, int r, vector<int> &nums)
    {
        if (l < r)
        {
            int pivot = partition(l, r, nums);
            quicksort(l, pivot - 1, nums);
            quicksort(pivot + 1, r, nums);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        quicksort(0, nums.size() - 1, nums);
        return nums;
    }
};
