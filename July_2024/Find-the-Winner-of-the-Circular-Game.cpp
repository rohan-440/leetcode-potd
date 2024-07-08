class Solution
{
public:
    int f(int n, int k)
    {
        if (n == 1)
            return 1;
        int win = f(n - 1, k);
        int finWin = (win + k) % n;
        return finWin == 0 ? n : finWin;
    }
    int findTheWinner(int n, int k)
    {
        return f(n, k);
    }
};
