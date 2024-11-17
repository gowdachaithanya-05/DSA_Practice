#include <iostream>
#include <vector>
using namespace std;
// 643. Maximum Average Subarray I
// Solved
// Easy
// Topics
// Companies
// Facebook
// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000
 

// Constraints:

// n == nums.length
// 1 <= k <= n <= 105
// -104 <= nums[i] <= 104
//Sliding window pattern 

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_sum = 0;
        for(int i=0 ; i<k; i++ ){
            max_sum +=nums[i];
        }
        double new_sum = max_sum;
        for(int i = k; i< nums.size(); i++){
            new_sum = new_sum + nums[i] - nums[i-k];
            max_sum = max(max_sum, new_sum);
        }
        return max_sum/=k; 
    }
};