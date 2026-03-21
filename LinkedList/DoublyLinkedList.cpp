#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertArrayToDoublyLinkedList(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *curr = head;
    for(int i=1; i<arr.size(); i++){
        Node *newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

void printDoublyLinkedList(Node *head){
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *deletionInDoublyLinkedList(Node *head, int pos){
    if(head==nullptr){
        return head;
    }
    if(pos==1){
        Node *tmp = head;
        head = head->next;
        head->prev = nullptr;
        delete tmp;
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    int cnt = 0;
    while(curr != nullptr && cnt < pos - 1){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(cnt == pos - 1){
        prev->next = curr->next;
        if(curr->next != nullptr){
            curr->next->prev = prev;
        }
        delete curr;
    }
    return head;
}

Node *insertInDoublyLinkedList(Node *head, int pos, int data){
    Node *newNode = new Node(data);
    if(head==nullptr){
        return newNode;
    }
    if(pos==1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    int cnt = 0;
    while(curr != nullptr && cnt < pos-1){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(cnt == pos-1){
        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = curr;
        if(curr != nullptr){
            curr->prev = newNode;
        }
    }
    return head;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    Node *head = convertArrayToDoublyLinkedList(arr);
    Node *newHead = deletionInDoublyLinkedList(head, 3);
    Node *newHead2 = insertInDoublyLinkedList(newHead, 3, 10);

    printDoublyLinkedList(newHead2);
    return 0;
}