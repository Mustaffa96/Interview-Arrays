/*
You are given an array of size N. Rearrange the given array in-place such that all the negative numbers occur before positive numbers.(Maintain the order of all -ve and +ve numbers as given in the original array).
 

Example 1:

Input:
N = 4
Arr[] = {-3, 3, -2, 2}
Output:
-3 -2 3 2
Explanation:
In the given array, negative numbers
are -3, -2 and positive numbers are 3, 2. 
 

Example 2:

Input:
N = 5
Arr[] = {2, -4, 7, -3, 4}
Output:
-4 -3 2 7 4
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function Rearrange() which takes the array Arr[] and its size N as inputs and returns the array after rearranging with spaces between the elements of the array.

Expected Time Complexity: O(N. Log(N))
Expected Auxiliary Space: O(Log(N))

 

Constraints:
1 ≤ N ≤ 107
-1018 ≤ Elements of array ≤ 1018
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} // } Driver Code Ends




void Rearrange(int arr[], int n)
{
     vector<int> a(n);
     int k=0;
    for(int i=0;i<n;i++){
        a[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<0){
            arr[k++]=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            arr[k++]=a[i];
        }
    }
}
