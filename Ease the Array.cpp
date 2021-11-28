/*
Given an array of integers of size, N. Assume ‘0’ as the invalid number and all others as a valid number. Write a program that modifies the array in such a way that if the next number is a valid number and is the same as the current number, double the current number value and replace the next number with 0. After the modification, rearrange the array such that all 0’s are shifted to the end and the sequence of the valid number or new doubled number is maintained as in the original array.

Example 1:

â€‹Input : arr[ ] = {2, 2, 0, 4, 0, 8}
Output : 4 4 8 0 0 0
Explanation:
At index 0 and 1 both the elements are same.
So, we can change the element at index 0 to 
4 and element at index 1 is 0 then we shift 
all the values to the end of the array. 
So, array will become [4, 4, 8, 0, 0, 0].

Example 2:

Input : arr[ ] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
Output :  4 2 12 8 0 0 0 0 0 0


Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function modifyAndRearrangeArr() that takes an array (arr) and its size (n), and modifies it in-place.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
*/

// { Driver Code Starts
//Initial Template for C++

// C++ implementation to rearrange the array 
// elements after modification 
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        void modifyAndRearrangeArr(int arr[], int n) 
    { 
        for(int i=0;i<n-1;i++){
            if(i+1<n && arr[i]!=0 && arr[i]==arr[i+1]){
                arr[i]*=2;
                arr[i+1]=0;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
       if(arr[i]!=0){
           arr[count++]=arr[i];
       }
    }
    while(count<n){
        arr[count++]=0;
    }
    }
}; 


// { Driver Code Starts.
// Driver program to test above 
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        ob.modifyAndRearrangeArr(arr, n);
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
        
    }

	return 0; 
} 
  // } Driver Code Ends
