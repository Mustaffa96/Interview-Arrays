/*
Given two sorted arrays A and B of length L1 and L2, we can get a set of sums(add one element from the first and one from second). Find the N’th element in the set considered in sorted order.
Note: Set of sums should have unique elements.

Example 1:

Input: L1 = 2, L2 = 2
A = {1, 2}
B = {3, 4}
N = 3
Output: 6
Explaination: The set of sums are in 
the order 4, 5, 6.
Example 2:

Input: L1 = 5, L2 = 4
A = {1, 3, 4, 8, 10}
B = {20, 22, 30, 40}
N = 4
Output: 25
Explaination: The numbers before it 
are 21, 23 and 24.
Your Task:
You do not need to read input or print anything. Your task is to complete the function nthItem() which takes L1, L2, A, B, and the value N as input parameters and returns the Nth value of the set. If N is greater than the size of the set then it returns -1.

Expected Time Complexity: O(L1*L2)
Expected Auxiliary Space: O(L1*L2)

Constraints:
1 ≤ L1, L2 ≤ 500
1 ≤ A[i], B[i] ≤ 10000
1 ≤ N ≤ L1*L2


*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nthItem(int L1, int L2, int A[], int B[], int N)
    {
        set<int> s;
        for(int i=0;i<L1;i++){
            for(int j=0;j<L2;j++){
                int sum=A[i]+B[j];
                s.insert(sum);
            }
        }
        if(N<=s.size()){
            auto it=s.begin();
            for(int i=1;i<N;i++){
                it++;
            }
            return *it;
        }
        else{
            return -1;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int L1, L2, N;
        cin>>L1>>L2;
        int A[L1], B[L2];
        for(int i = 0;i < L1;i++)
            cin>>A[i];
        for(int i = 0;i < L2;i++)
            cin>>B[i];
        cin>>N;
        
        Solution ob;
        cout<<ob.nthItem(L1, L2, A, B, N)<<endl;
    }
    return 0;
}  // } Driver Code Ends
