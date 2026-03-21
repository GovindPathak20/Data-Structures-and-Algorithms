#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Print the linked list
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}

// new Keyword in C++
// new heap pe memory allocate karta hai aur us memory ka address return karta hai

// Node *head = new Node(10);
// address store      heap par node banao