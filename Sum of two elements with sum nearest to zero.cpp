/*
Given an array of n integers

Example 1:

Input:
N = 3
arr[] = {-8 -66 -60}
Output: -68
Explanation: Sum of two elements closest to 
zero is -68 using numbers -60 and -8.
â€‹Example 2:

Input: 
N = 6
arr[] = {-21 -67 -37 -18 4 -65}
Output: -14
Explanation: Sum of two elements closest to
zero is -14 using numbers -18 and 4.

Your Task:
You don't need to read input or print anything. You just need to complete the function closestToZero() which takes an array arr[] and its size n as inputs and returns the maximum sum closest to zero that can be formed by summing any two elements in the array.


Expected Time Complexity: O(N*logN).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ N ≤ 5 * 105
-106 ≤ arr[i] ≤ 106
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here
                        if(n == 1)
                return arr[0] * 2;
            sort(arr, arr + n);
            if(arr[0] > 0)
                return arr[0] + arr[1];
            else if(arr[n - 1] < 0)
                return arr[n - 1] + arr[n - 2];
                
            int low = 0, high = n - 1, res = 0, absdiff = INT_MAX;
            
            while(low<high)
            {
                int diff = arr[low] + arr[high];
                if(diff == 0)
                    return 0;
                if(diff < 0)
                    low++;
                else
                    high--;
                if(abs(diff) < absdiff)
                {
                    absdiff = abs(diff);
                    res = diff;
                }
                else if(abs(diff) == absdiff)
                    res = max(res, diff);
            }
            return res;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends
