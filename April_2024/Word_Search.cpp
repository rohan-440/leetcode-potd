class Solution
{
public:
    bool dfs(int i, int j, int ind, vector<vector<char>> &board, string &word, vector<vector<int>> &vis)
    {
        if (ind == word.size() - 1 && word[ind] == board[i][j])
            return 1;
        vis[i][j] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int x = 0; x < 4; x++)
        {
            int r = i + dr[x];
            int c = j + dc[x];
            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == word[ind + 1] && vis[r][c] == 0)
            {
                vis[r][c] = 1;
                if (dfs(r, c, ind + 1, board, word, vis))
                    return 1;
                vis[r][c] = 0;
            }
        }
        return 0;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word, vis))
                    return 1;
            }
        }
        return 0;
    }
};