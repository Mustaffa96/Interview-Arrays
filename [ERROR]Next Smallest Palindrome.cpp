/*
Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:

Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
94188088149.
Example 2:

Input:
N = 5
Num[] = {2, 3, 5, 4, 5}
Output: 2 3 6 3 2
Explanation: Next smallest palindrome is
23632.
Your Task:
Complete the function generateNextPalindrome() which takes an array num, and an single integer n, as input parameters and returns an array of integers denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Num[i] <= 9
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
        vector<int>ans;
        int k=0;
        for(int i=n/2-1;i>=0;i--)
        {
            if(num[n-i-1] !=num[i])
            {
                k=1;
            }
            num[n-i-1]= num[i];
        }
        
        
        int flag=0;
        if(num[n/2]!=9  && n%2!=0)
        {
            num[n/2]+=1;
            
            
        for(int i=0;i<n;i++)
        {
            ans.push_back(num[i]);
        }
        
        
            return ans;
        }
        
        else
        {
        
        if(n%2!=0)
        {
        num[n/2]=0;  
        }
        
        for(int i=n/2-1;i>=0;i--)
        {
        
        if(num[i]!=9 )
        {
            flag=1;
            num[i]++;
            num[n-i-1]++;
          break;
        }
        else
        {
           num[i]=0; 
           num[n-i-1]='0';
        
        }
        
            
        }
        
        }
        
        
        for(int i=0;i<n;i++)
        {
            ans.push_back(num[i]);
        }
        
        
        if(!flag)
        {
            ans[0]=1;
            ans.push_back(1);
        }
        
        
        return  ans;
	}

};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
