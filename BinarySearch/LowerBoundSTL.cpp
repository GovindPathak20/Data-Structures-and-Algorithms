#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    sort(arr.begin(), arr.end());
    int lowerBoundIdx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();  // This returns an iterator pointing to the first element in the range [first, last) which does not compare less than target (i.e., it is greater than or equal to target). We subtract arr.begin() to get the index.

    // If searchSpace is between index 0 and 6 for example, then code will be:
    // int lowerBoundIdx = lower_bound(arr.begin()+2, arr.begin()+7, target) - arr.begin();  // This will search for the target in the range [2, 6] and return the index of the first element that is greater than or equal to target.
    
    cout << lowerBoundIdx << endl;

    return 0;
}