// Problem Statement: Given an integer N, return true it is an Armstrong number otherwise return false.
// An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int armstrong(int n){
     int original = n;
    //  int k =0;
     int sum = 0;
    //  while(n>0){
    //      k = k+1;
    //      n = n/10;
    //  }
    int k = to_string(n).length();
    while(n > 0){
        int digit = n % 10;
        sum += pow(digit, k);
        n = n / 10;
    }
     if (sum == original){
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
    if (armstrong(n)){
        cout << n <<" is armstrong";
    }
    else {
        cout << n <<" is not armstrong";
    }
    return 0;
}
