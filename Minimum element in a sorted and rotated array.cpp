/*
A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Example

Input
N = 5
arr[] = {4 ,5 ,1 ,2 ,3}
Output
1
Explanation: 1 is the minimum element in
the array.
Example

Input
N = 6
arr[] = {10, 20, 30, 40, 50, 5, 7}
Output
5
Explanation:
Here 5 is the minimum element.
 

Your Task:
Complete the function findMin() which takes an array arr[] and n, size of the array as input parameters, and returns the minimum element of the array.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(log N).

Constraints:
1 ≤ N ≤ 100000
1 ≤ A[i] ≤ 1000000
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
       for(int i = 1; i < n; i++) {
           if(arr[0] > arr[i])
               arr[0] = arr[i];
       }
       
       return arr[0];
        
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
