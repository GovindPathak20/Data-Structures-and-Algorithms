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
    int x;
    cin >> x;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    if(x == 1){
        Node *temp = head;
        head = head->next;
        delete temp;
    }else{
        int tmp = 0;
        // Considering 1-based indexing for the position of the node to be deleted
        Node *curr = head;
        Node *prev = nullptr;
        while(tmp < x - 1){
            prev = curr;
            curr = curr->next;
            tmp++;
        }
        prev->next = curr->next;
        delete curr;
    }
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}

// Considering 1-based indexing and 1 <= x <= length of the linked list.