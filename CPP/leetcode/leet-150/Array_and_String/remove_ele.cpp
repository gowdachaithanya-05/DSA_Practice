#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j =0 ;
        for(int i = m ; i<m+n; i++){
          
            if(j<n){
              nums1[i]= nums2[j];
                j++;
             }
            
        }
        return sort(nums1.begin(), nums1.end());
    }
};
