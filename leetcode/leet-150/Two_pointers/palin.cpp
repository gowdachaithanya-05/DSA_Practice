// // Approach 
// 1. Use two pointers low(beginning of string) and high(end of the string).
// 2. check if they are alphanumeric, if not skip them.
// 3. if they are alphanumeric, compare two pointers low and high (in lower case) 
//     if not equal return false;
//     if equal return true;

// Time complexity : O(n) as each char is processed only once;
// Space complexity : O(1);

class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.length();
        while(low < high){
            if(!isalnum(s[low])){
               low++;
            }
            else if(!isalnum(s[high])){
                high--;
            }
            else if(tolower(s[low]) != tolower(s[high])){
                return false;
            }
            else{
               low++;
                high--;
            }
        }
        return true;
    }
};