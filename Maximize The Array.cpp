/*
Given two integer arrays Arr1 and Arr2 of size N. Use the greatest elements from the given arrays to create a new array of size N such that it consists of only unique elements and the sum of all its elements is maximum. 
The created elements should contain the elements of Arr2 followed by elements of Arr1 in order of their appearance.


Example 1:

Input:
N = 5
Arr1 = {7, 4, 8, 0, 1}
Arr2 = {9, 7, 2, 3, 6}
Output: 9 7 6 4 8
Explanation: 9, 7, 6 are from 2nd array
and 4, 8 from 1st array.

Example 2:

Input: 
N = 5
Arr1 = {6, 7, 5, 3}
Arr2 = {5, 6, 2, 9} 
Output: 5 6 9 7 
Explanation: 5, 6, 9 are from 2nd array
and 7 from 1st array.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function maximizeArray() which takes the array arr1[], arr2[] and n as input parameters and returns the desired array of integers.


Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)


Constraints:
1 <= N <= 105
0 <= Arr1[i] <= 109
0 <= Arr2[i] <= 109
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
       vector<int> ans;
       unordered_set<int> set;
       priority_queue<int> mxh;
       for (int i = 0; i < n; i++) {
           mxh.push(arr1[i]);
           mxh.push(arr2[i]);
       }
       while (!mxh.empty()) {
           if (set.size() == n) break;
           set.insert(mxh.top());
           mxh.pop();
       }
       for (int i = 0; i < n; i++) {
           if (ans.size() == n) break;
           if (set.count(arr2[i]) > 0) {
               ans.push_back(arr2[i]);
               set.erase(arr2[i]);
           }
       }
       for (int i = 0; i < n; i++) {
           if (ans.size() == n) break;
           if (set.count(arr1[i]) > 0) {
               ans.push_back(arr1[i]);
               set.erase(arr1[i]);
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
