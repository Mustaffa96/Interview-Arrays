/*
Given a number n, find the smallest number that has same set of digits as n and is greater than n. If n is the greatest possible number with its set of digits, report it.

Example 1:

Input:
N = 143
Output: 314
Explanation: Numbers possible with digits 
1, 3 and 4 are: 134, 143, 314, 341, 413, 431.
The first greater number after 143 is 314.

â€‹Example 2:

Input: 
N = 431
Output: not possible
Explanation: Numbers possible with digits
1, 3 and 4 are: 134, 143, 314, 341, 413, 431.
Clearly, there's no number greater than 431.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findNext () which takes an integer N as input and returns the smallest number greater than N with the same set of digits as N. If such a number is not possible, return -1.


Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(LogN).


Constraints:
1 ≤ N ≤ 100000
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int findNext(int N) 
    {
    if(N == 1) return -1;
    string num = to_string(N);
    int i, j;
    for(i = num.length()-1; i > 0; i--){
        if(num[i] > num[i-1]) break;
    }
    if(i == 0) return -1;
    for(j = num.length()-1; j >= i; j--){
        if(num[i-1] < num[j]) {
      swap(num[i-1], num[j]);
         break;
        }
    }
    reverse(num.begin()+i, num.end());
    return stoi(num);
}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; cin >> n;
		Solution ob;
		int res = ob.findNext (n);
		if (res == -1)
		    cout << "not possible";
		else
		    cout << res;
		cout << endl; 
	}
}  // } Driver Code Ends
