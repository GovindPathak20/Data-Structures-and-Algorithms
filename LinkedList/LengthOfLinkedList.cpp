#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int ans = 0;
    Node *curr = head;
    while(curr != NULL){
        ans++;
        curr = curr->next;
    }

    cout << ans << endl;

    return 0;
}