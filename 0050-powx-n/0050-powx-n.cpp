class Solution {
public:

    double myPow(double x, long long n) {

        // Base case
        if (n == 0) {
            return 1.0;
        }

        // Negative exponent
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }

        // Even exponent
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        }

        // Odd exponent
        return x * myPow(x, n - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna