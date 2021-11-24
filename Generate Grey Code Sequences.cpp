/*
Given a number N, your task is to complete the function which generates all n-bit grey code sequences, a grey code sequence is a sequence such that successive patterns in it differ by one bit.

Example 1:

Input:
N = 2
Output: 00 01 11 10
Explanation: All 2-bit gray codes are
00, 01, 11, 10 such that successive
patterns in it differ by one bit.
Example 2:

Input:
N = 1
Output: 0 1
 

Your Task:
Complete the function generateCode() which takes an integer as input parameter and retruns an array of all N bit grey code sequence such that successive patterns in it differ by one bit.

Expected Time Complexity: O(N * 2N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 16
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*Returns an array of all n-bit gray codes sequence.
You are required to complete below method. */
class Solution{
  public:
  
    void recfunc(int N , vector <string> &ans){
    if(N==0){
        ans.push_back("");
        return;
    }
    recfunc(N-1 , ans);
    vector<string> temp;
    for(auto it : ans) temp.push_back("0"+it);
    reverse(ans.begin() , ans.end());
    for(auto it : ans) temp.push_back("1"+it);
    ans.clear();
    ans = temp;
    }
  
    vector <string> generateCode(int N)
    {
        vector<string> ans;
        recfunc(N , ans);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution obj;
		vector <string> res = obj.generateCode(n);
		for (string i : res) cout << i << " ";
        cout<<endl;
	}
	return 0;
}

  // } Driver Code Ends
