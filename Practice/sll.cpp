//singly linked list
#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;        
    Node* next;      
   
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


class sll {
public:
    void traverse(Node* head) {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    Node* insertbeg(Node* head, int val) {
        Node* newnode = new Node(val);
        newnode->next = head;
        return newnode;  
    }

    
    Node* insertend(Node* head, int val) {
        Node* newnode = new Node(val);
        if (head == nullptr) {
            return newnode; 
        }
        
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newnode;
        return head;  
    }

    Node* insertafter(Node*head, int target, int val){
        Node* cur = head;
        Node* newnode = new Node(val);
        while(cur != nullptr){
            if(cur->data == target){
               newnode->next = cur->next;
               cur->next = newnode;
               break;
            }
            cur = cur->next;
        }
         return head;
    }

};

int main() {
    Node* head = nullptr;
    sll list;  

    head = list.insertbeg(head, 10);
    head = list.insertbeg(head, 20);
    head = list.insertbeg(head, 30);

    cout << "Linked list after inserting at the beginning: ";
    list.traverse(head);

    head = list.insertend(head, 40);
    head = list.insertend(head, 50);

    cout << "Linked list after inserting at the end: ";
    list.traverse(head);

    head = list.insertafter(head, 10, 35);
    cout << "Linked list after inserting after 10: ";
    list.traverse(head);

    return 0;
}
