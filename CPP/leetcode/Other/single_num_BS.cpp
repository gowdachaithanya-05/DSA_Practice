// 540. Single Element in a Sorted Array
// Solved
// Medium
// Topics
// Companies
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = low + (high - low )/2;
            if(mid%2 == 1){
                mid --;
            }
            if(nums[mid]!= nums[mid+1]){
                high = mid;

            }
            else{
                low = mid+2;
            }
        }
        return nums[low];
        // unordered_map<int, int> mp;
        // for(int num : nums) {
        //     mp[num]++;
        // }
        // for(auto pair : mp) {
        //     if(pair.second == 1) {
        //         return pair.first;
        //     }
        // }
        // return -1;
    }
};