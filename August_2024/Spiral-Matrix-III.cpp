class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> v;
        v.push_back({rStart, cStart});
        int step = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        while (v.size() < rows * cols)
        {
            if (d == 0 || d == 2)
            {
                step++;
            }
            for (int i = 0; i < step; i++)
            {
                rStart += dir[d][0];
                cStart += dir[d][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    v.push_back({rStart, cStart});
            }
            d = (d + 1) % 4;
        }
        return v;
    }
};