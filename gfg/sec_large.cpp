//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
       int n = arr.size();
       int large = *max_element(arr.begin(), arr.end());
       int sec_large = -1;
       if(n<2) return -1;
       for(int i =0 ; i<n; i++){
           if(arr[i] > sec_large && arr[i]<large){
               sec_large = arr[i];
            }
          
       }
        if(large == sec_large){
               return -1;
           }
       else   {
           return sec_large;
       }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends