/*
Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and the right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping. (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).

Note: It may be assumed that the rectangles are parallel to the coordinate axis.

rectanglesOverlap

Example 1:

Input:
L1=(0,10)
R1=(10,0)
L2=(5,5)
R2=(15,0)
Output:
1
Explanation:
The rectangles overlap.
Example 2:

Input:
L1=(0,2)
R1=(1,1)
L2=(-2,-3)
R2=(0,2)
Output:
0
Explanation:
The rectangles do not overlap.

Your Task:
You don't need to read input or print anything. Your task is to complete the function doOverlap() which takes the points L1, R1, L2, and R2 as input parameters and returns 1 if the rectangles overlap. Otherwise, it returns 0.


Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)


Constraints:
-109<=x-coordinate,y-coordinate<=109
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {

       if(L1[0]>R2[0]||L2[0]>R1[0])
           return false;
       if(R1[1]>L2[1]||R2[1]>L1[1])
           return false;
       return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends
