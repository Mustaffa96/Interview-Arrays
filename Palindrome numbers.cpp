/*
Check if the binary representation of a number is palindrome or not.
 

Example 1:

Input:
N = 17
Output:
1
Explanation:
(17)10 = (10001)2
Which is pallindrome hence
output is 1.

Example 2:

Input:
N = 16
Output:
0
Explanation:
(16)10 = (10000)2
Which is not pallindrome 
hence output is 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isPallindrome() which takes an integer N as input parameters and returns 1 if the binary equivalent of N is a palindrome.
 

Expected Time Complexity: O(log N)
Expected Space Complexity: O(logN)
 

Constraints:
1 <= N <= 1018
*/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int isPallindrome(long long int N){
        // code here
       vector<int> v;
       int val=floor(log2(N));
       unsigned int temp=1<<val;
       for(int i=0;i<=val;i++)
       {
           if((N & (temp>>i))==(temp>>i))
           {
               v.push_back(1);
           }
           
           else
           {
               v.push_back(0);
           }
       }
       
       int i=0;
       int j=v.size()-1;
       
       while(i<=j)
       {
           if(v[i]!=v[j])
           {
               return 0;
           }
           
           i++;
           j--;
       }
       
       return 1;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.isPallindrome(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
