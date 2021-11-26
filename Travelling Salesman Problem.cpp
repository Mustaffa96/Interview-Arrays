/*
Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.
 

Example 1:

Input: cost = {{0,111},{112,0}}
Output: 223
Explanation: We can visit 0->1->0 and 
cost = 111 + 112.
Example 2:

Input: cost = {{0,1000,5000},{5000,0,1000},
{1000,5000,0}}
Output: 3000
Explanation: We can visit 0->1->2->0 and cost 
= 1000+1000+1000 = 3000
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function total_cost() which takes cost as input parameter and returns the total cost to visit each city exactly once starting from city 0 and again comback to city 0.
 

Expected Time Complexity: O(2n * n2)
Expected Space Compelxity: O(2n * n)
 

Constraints:
1 <= n <= 10
1 <= cost[i][j] <= 103
*/

// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

int solve(vector<vector<int>>&cost, int i, int depth, vector<bool>& visited)
{
    const int n = cost.size();
    if(depth==n)
        return cost[i][0];

    int ans=INT_MAX;
    visited[i] = true;
    for(int j=0;j<n;j++)
    {
        if(!visited[j])
        {
            visited[j] = true;
            ans = min(ans, cost[i][j] + solve(cost, j, depth+1, visited));
            visited[j] = false;
        }
    }
    visited[i] = false;
    return ans;
}
int total_cost(vector<vector<int>>cost){
    // Code here
    vector<bool> visited(cost.size(), false);
    return solve(cost, 0, 1, visited);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
