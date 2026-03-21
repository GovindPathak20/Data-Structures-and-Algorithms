#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 2;
    int *y = &x;
    cout << y << endl;  // Here y is a pointer variable that holds the address of x
    cout << *y << endl; // Here *y is used to access the value stored at the address that y points to, which is the value of x (2)
    return 0;
}