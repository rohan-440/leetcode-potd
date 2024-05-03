class Solution
{
public:
    int compareVersion(string ver1, string ver2)
    {
        int i = 0;
        int j = 0;
        while (i < ver1.size() && j < ver2.size())
        {
            int x = i;
            while (x < ver1.size())
            {
                if (ver1[x] == '.')
                    break;
                x++;
            }
            int y = j;
            while (y < ver2.size())
            {
                if (ver2[y] == '.')
                    break;
                y++;
            }
            int v1 = stoi(ver1.substr(i, x));
            int v2 = stoi(ver2.substr(j, y));
            if (v1 < v2)
                return -1;
            else if (v1 > v2)
                return 1;
            i = x + 1;
            j = y + 1;
        }
        while (i < ver1.size())
        {
            int x = i;
            while (x < ver1.size())
            {
                if (ver1[x] == '.')
                    break;
                x++;
            }
            int v1 = stoi(ver1.substr(i, x));
            if (v1 < 0)
                return -1;
            else if (v1 > 0)
                return 1;
            i = x + 1;
        }
        while (j < ver2.size())
        {
            int y = j;
            while (y < ver2.size())
            {
                if (ver2[y] == '.')
                    break;
                y++;
            }
            int v2 = stoi(ver2.substr(j, y));
            if (v2 < 0)
                return 1;
            else if (v2 > 0)
                return -1;
            j = y + 1;
        }
        return 0;
    }
};