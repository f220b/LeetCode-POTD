// Last updated: 9/5/2026, 12:01:41 AM
class Solution {
public:
    int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
    int sumOfPrimesInRange(int n) {
        int r = reverse(n);
        int low = min(n, r), high = max(n, r);

        vector<int> isPrime(high + 2, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (int i = 2; i * i <= high + 1; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= high + 1; j += i)
                    isPrime[j] = 0;
            }
        }
        int sum = 0;
        for(int i = low; i <= high; i++) {
            if(isPrime[i])
                sum += i;
        }
        return sum;
    }
};