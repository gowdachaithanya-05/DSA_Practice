// 4. Find First and Last Position of Element in Sorted Array
// Solved
// Medium
// Topics
// Companies
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int s = -1;
        int  e = -1;
        while(low <= high){
            int mid = low + (high -low)/2;
            if(nums[mid]==target){
                s = mid;
                high = mid -1;
            }
            else if(nums[mid]< target){
                low = mid + 1;

            }
            else{
                high = mid - 1;
            }
        }
         low = 0;
         high = n-1;
        while(low<=high){
            int mid = low + (high -low)/2;
            if(nums[mid]==target){
                e = mid;
                low = mid + 1;
            }
            else if(nums[mid]< target){
                low = mid + 1;

            }
            else{
                high = mid - 1;
            } 
        }
        return {s , e};
    }
};