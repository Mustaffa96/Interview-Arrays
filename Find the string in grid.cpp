/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
 

Example 1:

Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: {{0,0}}
Expalnation: From (0,0) one can find "abc"
in horizontally right direction.
Example 2:

Input: grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
,word = "abe"
Output: {{0,0},{0,2},{1,0}}
Explanation: From (0,0) one can find "abe" in 
right-down diagonal. From (0,2) one can
find "abe" in left-down diagonal. From
(1,0) one can find "abe" in Horizontally right 
direction.
 

Your Task:
You don't need to read or print anyhting, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containg the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions strating from the same coordinates, the list should contain the coordinates only once. 
 

Expected Time Complexity: O(n*m*k) where k is constant
Exected Space Complexity: O(1)
 

Constraints:
1 <= n <= m <= 100
1 <= |word| <= 10
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
   const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

   bool search(vector<vector<char>> &grid, string &word, int i, int j, int n, int m) {
       if (grid[i][j] != word[0]) return false;
       for (int dir = 0; dir < 8; dir++) {
           int x = i + dx[dir], y = j + dy[dir];
           int index;
           for (index = 1; index < word.size(); index++) {
               if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != word[index]) break;
               x += dx[dir];
               y += dy[dir];
           }
           if (index == word.size()) return true;
       }
       return false;
   }
    
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
       vector<vector<int>> ans;
       int n = grid.size();
       int m = grid[0].size();
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               if (search(grid, word, i, j, n, m)) ans.push_back({i, j});
           }
       }
       return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends
