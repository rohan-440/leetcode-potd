class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int op = 0;
        for (int i = 0; i < logs.size(); i++)
        {
            int j = logs[i].size() - 2;
            int num = 0;
            while (j >= 0)
            {
                if (logs[i][j] == '.')
                    num++;
                j--;
            }
            cout << "num: " << num << endl;
            if (num == 2 && op > 0)
                op--;
            else if (num == 0)
                op++;
            cout << "op :" << op << endl;
        }
        return op < 0 ? 0 : op;
    }
};