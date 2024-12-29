// Online C++ compiler to run C++ program online

// reverse a number
#include <iostream>
using namespace std;
 int reverse(int N){
     int rn = 0;
     while(N>0){
         int digit = N % 10; //last digit 
         rn = (rn*10)+digit;
         N = N / 10;
     }
     return rn;
 }
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    int res = reverse(n);
    cout << "the reverse of n is : " << res;
    return 0;
}