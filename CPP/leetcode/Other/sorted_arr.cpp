class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int point = 0;
        for(int i = 0 ; i<n; i++){
            if(nums[i] > nums[(i+1)%n]){
                point++;
            }
        }
        if(point <=1){
            return true;
        }
        else return false;
    }
};