// 268. Missing Number
// Solved
// Easy
// Topics
// Companies
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int flag = 0;
        // int i;
        // sort(nums.begin(), nums.end());
        // for ( i = 0 ; i<n ; i++){
        //     if(nums[i] == i ){
        //         flag = 1;
        //     }
        //     else{
        //         flag = 0;
        //         break;
        //     }
            
        // }
        // return i;

        int s1 = n*(n+1)/2;
        int s2 = 0;
        for(int i = 0; i<n; i++){
            s2 +=nums[i];
        }
        int diff = s1 - s2;
        return diff;

    }
};