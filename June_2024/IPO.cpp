class Solution
{
public:
    // int f(int i ,int k,int w,vector<vector<int>> &arr,vector<vector<vector<int>>> &dp){
    //     if(i >= arr.size()) return w;
    //     if(k == 0) return w;
    //     if(dp[i][k][w] != -1) return dp[i][k][w];
    //     int take = 0;
    //     if(w >= arr[i][0]){
    //         take = f(i+1,k-1,w+arr[i][1],arr,dp);
    //     }
    //     int notake = f(i+1,k,w,arr,dp);
    //     return dp[i][k][w] = max(take,notake);
    // }
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<vector<int>> arr;
        for (int i = 0; i < profits.size(); i++)
        {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        priority_queue<int> pq;
        while (k--)
        {

            while (i < arr.size() && arr[i][0] <= w)
            {
                pq.push(arr[i][1]);
                i++;
            }
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};