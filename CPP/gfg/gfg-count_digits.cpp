// Given a number n. Count the number of digits in n which evenly divide n. Return an integer, total number of digits of n which divides n evenly.

// Note :- Evenly divides means whether n is divisible by a digit i.e. leaves a remainder 0 when divided.
 

// Examples :

// Input: n = 12
// Output: 2
// Explanation: 1, 2 when both divide 12 leaves remainder 0.

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
    //  vector <int> v;
    int original= N;
    int count = 0;
     while (N > 0){
     int digit = N %10;
         if (digit!=0 && original % digit ==0){
             count++;
         }
         N = N/10;
     }
    return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends