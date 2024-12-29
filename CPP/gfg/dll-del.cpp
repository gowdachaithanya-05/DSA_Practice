// Delete in a Doubly Linked List
// Difficulty: EasyAccuracy: 42.98%Submissions: 151K+Points: 2
// Given a Doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

// Examples:

// Input: LinkedList = 1 <--> 3 <--> 4, x = 3
// Output: 1 <--> 3
// Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
// Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
// Output: 5 <--> 2 <--> 9
// Explanation:

// Constraints:
// 2 <= size of the linked list <= 106
// 1 <= x <= size of the linked list 
// 1 <= node->data <= 104

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// A node of the doubly linked list
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
Node *push(Node *tail, int new_data) {
    // Allocate node
    Node *newNode = new Node(new_data);

    // Since we are adding at the end, next is NULL
    newNode->next = NULL;

    // Make newNode's previous pointer point to the current tail
    newNode->prev = tail;

    // If the tail is not null, link it to the new node
    if (tail != NULL)
        tail->next = newNode;

    // Return the new node as the new tail
    return newNode;
}

bool verifyDLL(Node *head) {
    int c1 = 0;
    Node *tmp = head;
    while (tmp->next) {
        c1++;
        tmp = tmp->next;
    }
    int c2 = 0;
    while (tmp->prev) {
        c2++;
        tmp = tmp->prev;
    }
    return c1 == c2;
}

// Function to print nodes in a given doubly linked list
void printList(Node *head) {
    // If list is empty
    if (head == NULL)
        return;
    if (!verifyDLL(head))
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        if (head == nullptr) return nullptr;  // Check if list is empty

        // If the head is the node to be deleted
        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return head;
        }

        Node* cur = head;
       
         for (int i = 1; cur && i < x; ++i) {
        cur = cur -> next;
    }
        if (cur == nullptr) return head;  

        if (cur->next != nullptr) {
            cur->next->prev = cur->prev;
        }
        if (cur->prev != nullptr) {
            cur->prev->next = cur->next;
        }

        delete cur;  
        return head;
    }
};



//{ Driver Code Starts.

// Driver code
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            tail = push(tail, arr[i]);
        }

        int x;
        cin >> x;
        cin.ignore();

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        cout << "\n";
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends