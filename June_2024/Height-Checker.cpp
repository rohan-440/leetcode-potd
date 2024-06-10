class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        for (int i; i < expected.size(); i++)
            cout << expected[i] << " ";

        int numInd = 0;
        for (int i = 0; i < expected.size(); i++)
        {
            if (heights[i] != expected[i])
                numInd++;
        }
        return numInd;
    }
};