#include <iostream>
using namespace std;
// 50. Pow(x, n)
// Solved
// Medium
// Topics
// Companies
// Facebook
// Amazon
// Bloomberg
// LinkedIn
// Google
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104
//recursive call is used to handle mod 
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modExp(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) { 
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;
        
        return (modExp(5, even_count, MOD) * modExp(4, odd_count, MOD)) % MOD;
    }
};
