// Upper Bound - Smallest index of an element greater than the target => arr[idx] > target
// arr[] = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12] n = 10, target = 6 => output = 3 (arr[3] = 7 > target)
// target = 12 => output = 10 (arr[10] is out of bound, so return n)
// target = 13 => output = 10 (arr[10] is out of bound, so return n)
// target = 0 => output = 0 (arr[0] = 2 > target)

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int target){
    int n = arr.size();
    int lo = 0, hi = n-1;
    int ans = n;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] > target){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return ans;
}

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

    int ub = upperBound(arr, target);

    cout << ub << endl;

    return 0;
}