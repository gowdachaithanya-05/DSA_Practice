// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 void divisors(int n){
     vector <int> v;
     for(int i = 1; i<=n ; i++){
        if (n%i ==0)
            v.push_back(i);
        }  
     for(auto it : v){
         cout << it<< " ";
     }
 }
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    cout << "Divisors of n : ";
    divisors(n);
    return 0; 
}