/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
  int largestHist(int arr[],int n) 
{ 
   stack<int> result; 
   int top_val; 
   int max_area = 0;  
   int area = 0; 
   int i = 0; 
   while (i < n) { 
       if (result.empty() || arr[result.top()] <= arr[i]) 
           result.push(i++); 
 
       else {  
           top_val = arr[result.top()]; 
           result.pop(); 
           area = top_val * i; 
 
           if (!result.empty()) 
               area = top_val * (i - result.top() - 1); 
           max_area = max(area, max_area); 
       } 
   } 
   while (!result.empty()) { 
       top_val = arr[result.top()]; 
       result.pop(); 
       area = top_val * i; 
       if (!result.empty()) 
           area = top_val * (i - result.top() - 1); 
 
       max_area = max(area, max_area); 
   } 
   return max_area; 
}
  
    int maxArea(int M[MAX][MAX], int n, int m) {
   int res = largestHist(M[0],m); 
 
   for (int i = 1; i < n; i++) { 
 
       for (int j = 0; j < m; j++) 
           if (M[i][j]) 
               M[i][j] += M[i - 1][j];

       res = max(res, largestHist(M[i],m)); 
   } 
       return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
