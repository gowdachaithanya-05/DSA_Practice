// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to solve 0/1 Knapsack problem and track items included
// int knapSack(int W, int wt[], int val[], int n, vector<vector<int>>& dp, vector<int>& parent) {
//     // Create a 2D vector to store the maximum value for each subproblem
//     dp.resize(n + 1, vector<int>(W + 1, 0));
//     parent.resize(n + 1, -1);

//     // Build dp table in bottom up manner
//     for (int i = 1; i <= n; ++i) {
//         for (int w = 1; w <= W; ++w) {
//             if (wt[i - 1] > w) {
//                 dp[i][w] = dp[i - 1][w];
//             } else {
//                 dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
//                 if (dp[i][w] == val[i - 1] + dp[i - 1][w - wt[i - 1]]) {
//                     parent[i] = w - wt[i - 1];
//                 }
//             }
//         }
//     }

//     // The maximum value will be in dp[n][W]
//     return dp[n][W];
// }

// // Function to print items included in the knapsack
// void printItemsIncluded(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {
//     // Track items included
//     vector<int> itemsIncluded;
//     int totalWeight = W;
//     for (int i = n; i > 0 && totalWeight > 0; --i) {
//         if (dp[i][totalWeight] != dp[i - 1][totalWeight]) {
//             itemsIncluded.push_back(i - 1);
//             totalWeight -= wt[i - 1];
//         }
//     }

//     // Print items included
//     cout << "Items included in the knapsack:" << endl;
//     for (int i = itemsIncluded.size() - 1; i >= 0; --i) {
//         cout << "Item " << (itemsIncluded[i] + 1) << " (Value: " << val[itemsIncluded[i]] << ", Weight: " << wt[itemsIncluded[i]] << ")" << endl;
//     }
// }

// // Driver code
// int main() {
//     int n;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     int val[n], wt[n];
//     cout << "Enter the weights of the items: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> wt[i];
//     }

//     cout << "Enter the profits of the items: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> val[i];
//     }

//     int W;
//     cout << "Enter the weight capacity of the knapsack: ";
//     cin >> W;

//     vector<vector<int>> dp;
//     vector<int> parent;
//     int maxProfit = knapSack(W, wt, val, n, dp, parent);
//     cout << "Maximum profit that can be put in the knapsack: " << maxProfit << endl;

//     printItemsIncluded(W, wt, val, n, dp);

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;


// Function to print items included in the knapsack
int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build dp table in bottom up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }
    
    int maxValue = dp[n][W];
   
   // to print the table 
    for (int i = 0; i < dp.size(); i++) { 
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " "; 
        }
        cout << endl; 
    }

    // Track items included
    vector<int> itemsIncluded;
    int totalWeight = W;
    for (int i = n; i > 0 && totalWeight > 0; --i) {
        if (dp[i][totalWeight] != dp[i - 1][totalWeight]) {
            itemsIncluded.push_back(i-1);
            totalWeight -= wt[i-1];
        }  
    }
     // Print items included
    cout << "Items included in the knapsack:" << endl;
    for (int i = itemsIncluded.size() - 1; i >= 0; --i) {
        cout << "Item " << (itemsIncluded[i] + 1) << " (Value: " <<
                val[itemsIncluded[i]] << ", Weight: " << wt[itemsIncluded[i]]
                << ")" << endl;
    }
    
    return maxValue;

}

// Driver code
int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    int W;
    cout << "Enter the weight capacity of the knapsack: ";
    cin >> W;

    int maxProfit = knapSack(W, wt, val, n);
    cout << "Maximum profit that can be put in the knapsack: " << maxProfit << endl;

  
    return 0;
}

