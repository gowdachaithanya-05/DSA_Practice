#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
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
                return {i,mpp[diff]};
            }
        }
        return { };
    }
    
};