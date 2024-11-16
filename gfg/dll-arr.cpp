// Introduction to Doubly Linked List
// Difficulty: EasyAccuracy: 76.51%Submissions: 39K+Points: 2
// Geek is learning data structures and is familiar with linked lists, but he's curious about how to access the previous element in a linked list in the same way that we access the next element. His teacher explains doubly linked lists to him.

// Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.

// Example 1:

// Input:
// n = 5
// arr = [1,2,3,4,5]
// Output:
// 1 2 3 4 5
// Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.
// Example 2:

// Input:
// n = 1
// arr = [1]
// Output:
// 1
// Explanation: Linked list for the given array will be 1.
// Constraints:
// 1 <= n <= 105
// 1 <= arr[i] <= 100

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function constructDLL() which takes arr[] as input parameters and returns the head of the Linked List.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    Node* prev;
    int data;
    Node* next;

    Node() {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value) {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

void printList(Node* node) {
    Node* tmp = node;
    int c1 = 0, c2 = 0;
    if (tmp) {
        while (tmp->next != NULL) {
            c1++;
            tmp = tmp->next;
        }
        while (tmp->prev != NULL) {
            c2++;
            tmp = tmp->prev;
        }
        if (c1 != c2) {
            cout << "-1\n";
            return;
        }
    }
    while (tmp) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        if(arr.empty()) return nullptr; 
        Node *head = new Node(arr[0]);
        Node *cur = head;
        Node *prev = nullptr;
        // while(cur->next!=nullptr){
        //     prev = cur;
        //     cur = cur->next;
            
        // }
        for(int i = 1; i<arr.size(); i++){
            Node *newnode = new Node(arr[i]);
            cur->next = newnode;
            newnode->prev = cur;
            cur = newnode; 
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        Node* ans = obj.constructDLL(arr);
        printList(ans);

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends