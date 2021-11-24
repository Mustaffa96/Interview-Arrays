/*
Write a program to print Binary representation of a given number N.

Example 1:

Input:
N = 2
Output:
000000000000000000000000000010
Explanation:
The binary representation of 2 is '10'
but we need to print in 30 bits so append
remaining 0's in the left.
Example 2:

Input:
N = 5
Output:
000000000000000000000000000101
Explanation:
The binary representation of 5 is '101'.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function getBinaryRep() which takes an Integer N as input parameter and returns a string of size 30 which is the binary representation of N.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^9
*/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    string getBinaryRep(int N)
    {

       string res="";
       
       
       while(N>=1)
       {
           res+=(to_string(N%2));
           
           N=N/2;
       }
       
       
       while(res.length()<30)
       {
           res+='0';
       }
       
       
       reverse(res.begin(),res.end());
       
       return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
       
        Solution ob;
        string ans = ob.getBinaryRep(N);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
