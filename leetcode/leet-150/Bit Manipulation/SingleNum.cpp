// 136. Single Number
// Solved
// Easy
// Topics
// Companies
// Hint
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
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

        int res = 0;
        for(int num : nums){
            res = res ^ num; // xoring with itself give 0 and with 0 gives itself
        } 
        return res;
    }
};
