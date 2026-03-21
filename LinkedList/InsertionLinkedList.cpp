#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node* insertAtHead(Node *head, int x){
    Node *newNode = new Node(x);
    if(head==nullptr){
        return newNode;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtTail(Node *head, int x){
    Node *newNode = new Node(x);
    if(head==nullptr){
        return newNode;
    }
    Node *curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

Node *insertAtPos(Node *head, int pos, int x){
    Node *newNode = new Node(x);
    if(pos==1){
        return insertAtHead(head, x);
    }
    Node *prev = NULL;
    Node *curr = head;
    int cnt = 0;
    while(curr != nullptr && cnt < pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(cnt==pos){
        prev->next = newNode;
        newNode->next = curr;
    }
    return head;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node *newHead = insertAtHead(head, 60);
    Node *newHead2 = insertAtTail(newHead, 70);
    Node *newHead3 = insertAtPos(newHead2, 4, 80);

    Node *curr = newHead;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}