/*
Given are the heights of certain Buildings which lie adjacent to each other. Sunlight starts falling from the left side of the buildings. If there is a building of a certain Height, all the buildings to the right side of it having lesser heights cannot see the sun. The task is to find the total number of such buildings that receive sunlight.

 

Example 1:

Input:
N = 6
H[] = {6, 2, 8, 4, 11, 13}
Output:
4
Explanation:
Only buildings of height 6, 8, 11 and
13 can see the sun, hence output is 4.
 

Example 2:

Input:
N = 5
H[] = {2, 5, 1, 8, 3}
Output:
3
Explanation:
Only buildings of height 2, 5 and 8
can see the sun, hence output is 3.
 

Example 3:

Input:
N = 7
H[] = {3, 4, 1, 0, 6, 2, 3}
Output:
3
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function longest() which takes the array A[] and its size N as inputs and returns the desired output.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ N ≤ 105
1 ≤ Hi ≤ 105
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int longest(int arr[],int n)
    {
        
       int count=1;
       int hb = arr[0];
       for(int i=1;i<n;i++){
           if(arr[i]>=hb){
               hb=arr[i];
               count++;
           }
       }
       return count;
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
        int i, arr[n+5];
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution ob;
        cout<<ob.longest( arr, n )<<endl;
    }
    return 0;
}  // } Driver Code Ends
