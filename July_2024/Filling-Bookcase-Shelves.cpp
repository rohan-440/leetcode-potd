class Solution
{
public:
    int max_width;
    int f(int i, int width, int height, vector<vector<int>> &books, vector<vector<int>> &dp)
    {
        if (i >= books.size())
            return height;
        if (dp[i][width] != -1)
            return dp[i][width];
        int take = INT_MAX;
        // int notake = INT_MAX;
        if (books[i][0] <= width)
        {
            take = f(i + 1, width - books[i][0], max(height, books[i][1]), books, dp);
        }
        int notake = height + f(i + 1, max_width - books[i][0], books[i][1], books, dp);
        return dp[i][width] = min(take, notake);
    }
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int height = 0;
        max_width = shelfWidth;
        vector<vector<int>> dp(books.size() + 1, vector<int>(shelfWidth + 1, -1));
        return f(0, shelfWidth, height, books, dp);
    }
};