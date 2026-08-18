class Solution {
public:
    long long power(long long base, long long exp) {
        const long long MOD = 1000000007;

        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);

        if (exp % 2 == 0) {
            return (half * half) % MOD;
        } 
        else {
            return (half * half % MOD * base) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long even = power(5, evenPositions);
        long long odd = power(4, oddPositions);

        return (even * odd) % 1000000007;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna