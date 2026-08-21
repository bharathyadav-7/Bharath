class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        int sum=0;
        while(num != 0){
            int digit=num %10;
            sum += digit;
            num /=10;
        }
        if(sum > 9){
            return addDigits(sum);
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna