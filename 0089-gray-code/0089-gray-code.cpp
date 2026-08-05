class Solution {
public:
    vector<int> grayCode(int n) {
        auto generate = [&](auto &&self, int n) -> vector<int> {
            if (n == 0) return {0};

            vector<int> temp = self(self, n - 1);
            int m = temp.size();

            for (int i = m - 1; i >= 0; i--) {
                temp[i] <<= 1;                     // append 0
                temp.push_back(temp[i] | 1);       // append 1 (from back)
            }

            return temp;
        };

        return generate(generate, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna