class Solution
{
    /*
    1 -> 1
    2 -> 0
    3 -> 0

    */
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return 0;
        map<int, int> mp;
        for (auto x : hand)
            mp[x]++;
        auto x = mp.begin();
        while (x != mp.end())
        {
            if (x->second > 0)
            {
                for (int i = 0; i < groupSize; i++)
                {
                    if (mp[x->first + i] > 0)
                        mp[x->first + i]--;
                    else
                        return 0;
                }
            }
            else
                x++;
        }
        return 1;
    }
};