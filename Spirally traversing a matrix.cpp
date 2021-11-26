/*
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c), for returning the answer only.

Constraints:
1 <= r, c <= 100
0 <= matrixi <= 100
*/


// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {

       int dir = 1;
       vector<int> ans;
       int cnt = 0, i = 0, j = 0;
       vector<vector<bool>> vis(r,vector<bool>(c,false));
       
       while(cnt<r*c){
           if(dir % 4 == 1){ // right
               if(vis[i][j]) j++;
               while(j<c && !vis[i][j]){
                   ans.push_back(matrix[i][j]);
                   vis[i][j++] = true;
                   cnt++;
               }
               j--;
               dir++;
           }
           if(dir % 4 == 2){ // down
               if(vis[i][j]) i++;
               while(i<r && !vis[i][j]){
                   ans.push_back(matrix[i][j]);
                   vis[i++][j] = true;
                   cnt++;
               }
               i--;
               dir++;
           }
           if(dir % 4 == 3){ // left
               if(vis[i][j]) j--;
               while(j>=0 && !vis[i][j]){
                   ans.push_back(matrix[i][j]);
                   vis[i][j--] = true;
                   cnt++;
               }
               j++;
               dir++;
           }
           if(dir % 4 == 0){ // up
               if(vis[i][j]) i--;
               while(i>=0 && !vis[i][j]){
                   ans.push_back(matrix[i][j]);
                   vis[i--][j] = true;
                   cnt++;
               }
               i++;
               dir++;
           }
       }
       return (ans);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
