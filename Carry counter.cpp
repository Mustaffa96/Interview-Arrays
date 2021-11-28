/*
Given two numbers in the form of Strings. Find the count of carries in their addition.

 

Example 1:

Input:
N = "34", M = "25"
Output:
0
Explanation:
There are no carries when N and M
are added.
Example 2:

Input:
N = "4634", M = "1757"
Output:
2
Explanation:
There are 2 carries when N and M
are added.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function getCarries() which takes two Strings N and M as input and returns an integer denoting the answer.

 

Expected Time Complexity: O(|N|)
Expected Auxiliary Space: O(|N|)

 

Constraints:
1 <= |N|,|M| <= 105
*/

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int getCarries(string N , string M) {
        int ans = 0, c = 0;
        int n = N.size();
        int m = M.size();
        while(n >= 0 && m >= 0)
        {
            int sum = (N[n] - '0') + (M[m] - '0') + c;
            if(sum >= 10)
            {
                ans++;
                c = sum/10;
            }
            else
                c = 0;
            n--;
            m--;
        }
        while(n >= 0)
        {
            int sum = (N[n] - '0') + c;
            if(sum > 9)
            {
                ans++;
                c = sum/10;
            }
            else
                break;
            n--;
        }
        while(m >= 0)
        {
            int sum = (M[m] - '0') + c;
            if(sum > 9)
            {
                ans++;
                c = sum/10;
            }
            else
                break;
            m--;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.getCarries(N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
