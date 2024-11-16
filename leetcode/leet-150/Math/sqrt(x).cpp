// 69. Sqrt(x)
// Solved
// Easy
// Topics
// Companies
// Hint
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


class Solution {
public:
    int mySqrt(int x) {
    int low = 0;
    int high = x;
    if (x<2) return x;
    while(low <= high){
        long long  mid = low + (high -low )/2;
        long long  ms = mid * mid;
        if(ms < x){
            low = mid + 1;
        }
        else if(ms > x){
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return high ; 
    }
};