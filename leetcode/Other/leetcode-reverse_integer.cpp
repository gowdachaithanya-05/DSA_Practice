class Solution {
public:
    long reverse(int x) {
        long rn = 0;  
        while (x != 0) {
            int digit = x % 10;
            rn = (rn * 10) + digit;
            x = x / 10;
        }
        if (rn > INT_MAX || rn < INT_MIN) {
            return 0;
        }
        return rn; 
    }
};
