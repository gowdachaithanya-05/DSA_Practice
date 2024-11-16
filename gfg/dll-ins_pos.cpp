// Doubly linked list Insertion at given position
// Difficulty: BasicAccuracy: 47.13%Submissions: 124K+Points: 1
// Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list and return the head of updated list.

// Examples:

// Input: LinkedList: 2<->4<->5, p = 2, x = 6 
// Output: 2<->4<->5<->6
// Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 3 (0-based indexing).
// Input: LinkedList: 1<->2<->3<->4, p = 0, x = 44
// Output: 1<->44<->2<->3<->4
// Explanation: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 1 (0-based indexing).
// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= p < size of doubly linked list <= 106
// 1 <= x <= 106

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};


// } Driver Code Ends
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node *nn = new Node(data);
        if(pos == 0){
            nn->next = head;
            if(head != nullptr) head->prev = nn;
            head = nn;
            return head;
        }
        Node* cur = head;
          for (int i = 0; i < pos && cur != nullptr; ++i) {
               cur = cur->next;
          }
          
          if(cur == nullptr)  return head;
        
        nn->next = cur->next;
        if (cur->next!=nullptr) cur->next->prev = nn;
        cur->next = nn;
        nn->prev = cur;

        return head;
    }
};

//{ Driver Code Starts.

Node *insert(Node *head, int x) {
    if (head == NULL) {
        return new Node(x);
    }
    Node *n = new Node(x);

    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head) {
    // The purpose of below two loops is
    // to test the created DLL
    Node *temp = head;
    if (temp != NULL) {
        int ct1 = 0, ct2 = 0;
        while (temp->next != NULL)
            temp = temp->next, ct1++;
        while (temp->prev != NULL)
            temp = temp->prev, ct2++;
        if (ct1 != ct2) {
            cout << -1 << "\n";
            return;
        }
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after reading T to use getline properly

    while (t--) {
        Node *head = NULL;
        Node *root = NULL;
        vector<int> arr;
        string input;
        getline(cin, input);    // Read the entire line as input
        stringstream ss(input); // Use stringstream to split the input into integers
        int number;
        while (ss >> number) {
            arr.push_back(number); // Add each number to the vector
        }
        if (arr.empty()) {
            return NULL; // Return NULL if the vector is empty
        }
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            head = insert(head, x);
            if (root == NULL)
                root = head;
        }
        head = root;
        int pos, data;
        cin >> pos >> data;
        cin.ignore();
        Solution ob;
        head = ob.addNode(head, pos, data);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends