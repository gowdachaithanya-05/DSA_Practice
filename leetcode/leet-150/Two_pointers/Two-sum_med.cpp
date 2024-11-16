// 167. Two Sum II - Input Array Is Sorted
// Solved
// Medium
// Topics
// Companies
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > mpp;
        int n = nums.size();
        for (int i = 0; i<n; i++){
            mpp[nums[i]] = i;
        }
        for (int i =0 ; i< n ; i++){
            int diff = target - nums[i];
            if(mpp.find(diff) != mpp.end() && mpp[diff] !=i){
                return {i+1 , mpp[diff] + 1};
            }
        }
        return { };
    }
    
};