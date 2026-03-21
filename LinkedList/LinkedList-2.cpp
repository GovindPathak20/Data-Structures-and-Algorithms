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

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}