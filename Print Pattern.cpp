/*
Print a sequence of numbers starting with N where A[0] = N, without using loop, in which  A[i+1] = A[i] - 5,  until A[i] > 0. After that A[i+1] = A[i] + 5  repeat it until A[i] = N.

Example 1:

Input: N = 16
Output: 16 11 6 1 -4 1 6 11 16
Explaination: The value decreses until it 
is greater than 0. After that it increases 
and stops when it becomes 16 again.
Example 2:

Input: N = 10
Output: 10 5 0 5 10
Explaination: It follows the same logic as 
per the above example.
Your Task:
You do not need to read input or print anything. Your task is to complete the function pattern() which takes N as input parameters and returns a list containing the pattern.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 104 
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void helper(int M, int N, vector<int> &ans,int k)
   {
       if(M==N)
       {
           ans.push_back(M);
           return;
       }
       ans.push_back(M);
       if(M<=0)
       {
           k=-k;
       }
       helper(M+k,N,ans,k);
   }

    vector<int> pattern(int N){
       vector<int> ans;
       ans.push_back(N);
       helper(N-5,N,ans,-5);
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
