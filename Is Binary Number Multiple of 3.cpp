/*
Given a binary number, Find, if given binary number is a multiple of 3. The given number can be big upto 2^10000. It is recommended to finish the task using one traversal of input binary string.

Example 1:

Input: S = "011"
Output: 1
Explanation: "011" decimal equivalent
is 3, which is divisible by 3.
â€‹Example 2:

Input: S = "100"
Output: 0
Explanation: "100" decimal equivalent
is 4, which is not divisible by 3.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isDivisible() which takes the string s as inputs and returns 1 if the given number is divisible by 3 otherwise 0.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 105
*/

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int odd=0,even=0;
	    int n=s.size();
	    for(int i=n-1;i>=0;i--){
	        if(i%2==0 && s[i]=='1'){
	            odd++;
	        }
	        else if(i%2!=0 && s[i]=='1'){
	            even++;
	        }
	    }
	    if(abs(odd-even)%3==0)
	        return 1;
	    return 0;
	}

};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}

  // } Driver Code Ends
