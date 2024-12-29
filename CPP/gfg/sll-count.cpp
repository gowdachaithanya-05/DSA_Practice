// Count Linked List Nodes
// Difficulty: BasicAccuracy: 85.99%Submissions: 219K+Points: 1
// Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

// Examples :

// Input: LinkedList : 1->2->3->4->5

// Output: 5
// Explanation: Count of nodes in the linked list is 5, which is its length.


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