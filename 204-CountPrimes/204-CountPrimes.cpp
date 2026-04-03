// Last updated: 4/3/2026, 2:01:25 PM
class Solution {
public:
    // TC: O(n log log n)
    // SC: O(n + 1)
    int countPrimes(int n) {
        // Create an array of size n + 1 to mark prime numbers
        int primes[n + 1];

        // Initialize all elements to 1, assuming all numbers are prime
        // initially
        for (int i = 0; i < n; i++) {
            primes[i] = 1;
        }

        // Use the Sieve of Eratosthenes to find prime numbers
        for (int i = 2; i * i <= n; i++) {
            if (primes[i] == 1) { // Check if i is still marked as prime
                // Mark all multiples of i starting from i * i as non-prime
                for (int j = i * i; j < n + 1; j += i) {
                    primes[j] = 0; // Mark as non-prime
                }
            }
        }

        int count = 0;
        // Count the number of primes in the range [2, n)
        for (int i = 2; i < n; i++) {
            if (primes[i] == 1) {
                count++;
            }
        }

        // Return the total count of prime numbers found
        return count;
    }
};