class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int n = nums.size();
     int count = 0 ;
     int index = 0;
     for (int i = 0 ; i <n ; i++){
        if (nums[i] == 0){
            count++;
        }
         else{
            nums[index++] = nums[i];
         }
     }
        while(count > 0){
            nums[index++]=0;
            count--;
        }
       
    }

};