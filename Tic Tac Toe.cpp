/*
A Tic-Tac-Toe board is given after some moves are played. Find out if the given board is valid, i.e., is it possible to reach this board position after some moves or not.

Note that every arbitrary filled grid of 9 spaces isn’t valid e.g. a grid filled with 3 X and 6 O isn’t valid situation because each player needs to take alternate turns.

Note :  The game starts with X




Example 1:

Input:
board[] = {'X', 'X', 'O', 
           'O', 'O', 'X',
           'X', 'O', 'X'};
Output: Valid
Explanation: This is a valid board.

Example 2:

Input:
board[] = {'O', 'X', 'X', 
           'O', 'X', 'X',
           'O', 'O', 'X'};
Output: Invalid
Explanation: Both X and O cannot win.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isValid() which takes a character array of size 9 representing the board as input parameter and returns a boolean value denoting if it is valid or not.


Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)


Constraints:
Every character on the board can either be 'X' or 'O'.
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isValid(char board[9]){
       bool oo = false;
       bool xx = false;
       
       int x = 0, y = 0;
       
       for(int i = 0; i < 9 ;i++){
           if(board[i]=='O')x++;
           else y++;
       }
       
       if(y-x != 1)return false;
       
       for(int i = 0; i < 9 ;i+=3){
           if(board[i] =='O' && board[i+1] =='O' && board[i+2]=='O'){
               oo = true;
           }
           if(board[i] =='X' && board[i+1] =='X' && board[i+2]=='X'){
               xx = true;
           }
       }
       
       for(int i = 0; i < 3 ;i++){
           if(board[i] =='O' && board[i+3] =='O' && board[i+6]=='O'){
               oo = true;
           }
           if(board[i] =='X' && board[i+3] =='X' && board[i+6]=='X'){
               xx = true;
           }   
       }
       
       if(board[0] =='O' && board[4] =='O' && board[8]=='O'){
               oo = true;
           }
       if(board[0] =='X' && board[4] =='X' && board[8]=='X'){
           xx = true;
       } 
       
       if(board[2] =='O' && board[4] =='O' && board[6]=='O'){
               oo = true;
           }
       if(board[2] =='X' && board[4] =='X' && board[6]=='X'){
           xx = true;
       } 
       
       if(oo)return false;
       
       return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        char board[9];
        for (int i = 0; i < 9; i++) {
            cin >> board[i];
        }
        Solution ob;
        auto ans = ob.isValid(board);
        cout << (ans ? "Valid\n" : "Invalid\n");
    }
    return 0;
}  // } Driver Code Ends
