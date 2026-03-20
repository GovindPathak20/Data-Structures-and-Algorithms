// Lower Bound - Smallest index of an element greater than or equal to the target => arr[idx] >= target
// arr[] = [3, 5, 8, 15, 19] n = 5, target = 8 => output = 2 (arr[2] = 8 >= target)
// target = 9 => output = 3 (arr[3] = 15 >= target)
// target = 20 => output = 5 (arr[5] is out of bound, so return n)

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target){
    int lo = 0, hi = arr.size() - 1;
    int ans = arr.size();
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] >= target){
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
    int lowerBound = binarySearch(arr, target);

    cout << lowerBound << endl;

    return 0;
}

// Time Complexity: O(log n) for binary search, O(n log n) for sorting the array
// Space Complexity: O(1) for binary search, O(n) for sorting the array