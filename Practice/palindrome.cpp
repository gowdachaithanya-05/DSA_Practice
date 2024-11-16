// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
 int palindrome(int N){
     int orginal = N;
     int rn = 0;
     while(N>0){
         int digit = N % 10; //last digit 
         rn = (rn*10)+digit;
         N = N / 10;
     }
     if (orginal == rn){
         return true;
     }
     else {
         return false;
     }
 }
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    if (palindrome(n)){
        cout << n <<" is plaindrome";
    }
    else {
        cout << n <<" is not palindrome";
    }
    return 0;
}