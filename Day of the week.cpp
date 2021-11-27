/*
Write a program that calculates the day of the week for any particular date in the past or future.

Example 1:

Input:
d = 28, m = 12, y = 1995
Output:
Thursday
Explanation:
28 December 1995 was a Thursday.
Example 2:

Input:
d = 30, m = 8, y = 2010
Output:
Monday
Explanation:
30 August 2010 was a Monday.
Your Task:
You don't need to read input or print anything. Your task is to complete the function getDayOfWeek() which takes 3 Integers d, m and y denoting day, month and year as input and return a String denoting the answer.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 <= d <= 31
1 <= m <= 12
1990 <= y <= 2100
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string getDayOfWeek(int d, int m, int y) {

    static int t[] = { 0, 3, 2, 5, 0, 3,
    5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    int x= ( y + y / 4 - y / 100 +
    y / 400 + t[m - 1] + d) % 7;
    
    if(x==0)
    {
    return "Sunday";
    }
    if(x==1)
    {
    return "Monday";
    }
    if(x==2)
    {
    return "Tuesday";
    }
    if(x==3)
    {
    return "Wednesday";
    }
    if(x==4)
    {
    return "Thursday";
    }
    if(x==5)
    {
    return "Friday";
    }
    if(x==6)
    {
    return "Saturday";
    }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d,m,y;
        
        cin>>d>>m>>y;

        Solution ob;
        cout << ob.getDayOfWeek(d,m,y) << endl;
    }
    return 0;
}  // } Driver Code Ends
