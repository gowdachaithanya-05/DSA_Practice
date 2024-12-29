// Search in Linked List
// Difficulty: EasyAccuracy: 65.4%Submissions: 64K+Points: 2
// Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

// Example:

// Input:
// n = 4
// 1->2->3->4
// Key = 3
// Output:
// True
// Explanation:
// 3 is present in Linked List, so the function returns true.
// Your Task:
// Your task is to complete the given function searchKey(), which takes a head reference and key as Input and returns true or false boolean value by checking the key is present or not in the linked list.

// Constraint:
// 1 <= n <= 105
// 1 <= key <= 105

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int length = 0;
        if(head == nullptr) return 0;
        Node* cur = head;
        while(cur!= nullptr){
            cur = cur->next;
            length++;
        }
        return length;

        // Code here
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
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.getCount(head) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends