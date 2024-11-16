// 35. Search Insert Position
// Solved
// Easy
// Topics
// Companies
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int n = nums.size();
       int low = 0;
       int high = n-1;
       while(low <=high){
        int mid = low + (high - low)/2;
        if(nums[mid]==target){
            return mid ;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
       }
       return low; 
    }
};