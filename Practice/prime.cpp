// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 bool prime(int n){
 int count = 0;
 for(int i=1 ; i<=n; i++){
    if(n%i==0){
        count += 1;
        
    } 
 }
 if (count==2){
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
    if (prime(n)){
        cout << n << " is a prime number ";
    }
    else{
        cout << n << " is not a prime number";
    }
    
    return 0; 
}