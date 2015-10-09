//4ms
//any integer is composed of at most four squares.
class Solution {
public:
    int numSquares(int n) {
         while (n % 4 == 0)
        n /= 4;
    if (n % 8 == 7)
        return 4;
    for (int a=0; a*a<=n; ++a) {
        int b = sqrt(n - a*a);
        if (a*a + b*b == n)
            return !!a + !!b;
    }
    return 3;
    }
};

//12ms
//dynamic programming
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp {0};
        int m = dp.size();
        dp.resize(max(m, n+1), INT_MAX);
        for (int i=1, i2; (i2 = i*i)<=n; ++i)
            for (int j=max(m, i2); j<=n; ++j)
                if (dp[j] > dp[j-i2] + 1)
                    dp[j] = dp[j-i2] + 1;
        return dp[n];
    }
};