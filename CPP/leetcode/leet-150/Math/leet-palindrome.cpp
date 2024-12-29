#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int n) {
        int original =  n;
        long reverse;
        while(n>0){
         int digit = n % 10;
         reverse = (reverse*10) + digit;
         n = n/10;
        }
        if(original == reverse){
            return true;
        }
        else {
            return false; 
        }
    }
};