/*
Given a fraction. Convert it into a decimal. 
If the fractional part is repeating, enclose the repeating part in parentheses.
 

Example 1:

Input: numerator = 1, denominator = 3
Output: "0.(3)"
Explanation: 1/3 = 0.3333... So here 3 is 
recurring.
Example 2:

Input: numerator = 5, denominator = 2
Output: "2.5"
Explanation: 5/2 = 2.5
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function fractionToDecimal() which takes numerator and denominator as input parameter and returns its decimal form in string format.

Note: In case, the numerator is divisible by the denominator, just print the integer value.
 

Expected Time Compelxity: O(k) where k is constant.
Expected Space Complexity: O(k)
 

Constraints:
1 ≤ numerator, denominator ≤ 2000
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
    string final_result;
    
    int integer_part = numerator/denominator;
    int remainder = numerator%denominator;
    
    if(remainder == 0){
        return to_string(integer_part);
    } else {
       final_result = to_string(integer_part) + ".";
    }
    
    unordered_map<int,int> mymap;
    mymap.clear();
    int len = final_result.size();
    while(remainder!=0 && mymap.find(remainder) == mymap.end()){
        mymap[remainder] = len++;
        remainder *= 10;
        final_result += to_string(remainder/denominator);
        remainder %= denominator;
    }
    
    if(remainder != 0 ){
        final_result.insert(mymap[remainder],"(");
        final_result.insert(len+1,")");
    }
    
    return final_result;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
