class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        long long result = 0;
        long long Xor = 0;
        for (auto x : word)
        {
            int shift = x - 'a';
            Xor ^= (1 << shift);
            result += mp[Xor];
            for (char i = 'a'; i <= 'j'; i++)
            {
                int sh = i - 'a';
                long long checkprevXor = Xor ^ (1 << sh);
                result += mp[checkprevXor];
            }
            mp[Xor]++;
        }
        return result;
    }
};