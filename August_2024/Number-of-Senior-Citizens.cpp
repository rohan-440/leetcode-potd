class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int num = 0;
        for (int i = 0; i < details.size(); i++)
        {
            int unit = details[i][12] - '0';
            int tens = details[i][11] - '0';
            if (tens * 10 + unit > 60)
                num++;
        }
        return num;
    }
};