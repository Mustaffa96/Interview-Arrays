/*
Given a struct array of type Height, having two elements feet and inches. Find the maximum height among n heights, where height is calculated sum of feet and inches after converting feet into inches.

Example 1:

Input:
n = 2
h1 -> 1 2
h2 -> 2 1
Output: 
25
Explanation:
(1, 2) and (2, 1) are respective given heights.
After converting both heigths in to inches,
we get 14 and 25 as respective heights.
So, 25 is the maximum height.

Your Task: Your task is to only complete the function of find maximum height from given array
*/

// { Driver Code Starts
//Initial Template for C

#include <limits.h>
#include <stdio.h>

struct Height {
	int feet;
	int inches;
};


 // } Driver Code Ends
//User function Template for C

/*
Structure of the element of the array is as
struct Height {
	int feet;
	int inches;
};
*/
// function must return the maximum Height
// return the height in inches
int findMax(struct Height arr[], int n)
{
    int max=12*arr[0].feet+arr[0].inches;
    int h;
    for(int i=0;i<n;i++){
        h=12*arr[i].feet+arr[i].inches;
        if(h>max){
            max=h;
        }
    }
    return max;
}

// { Driver Code Starts.

// driver program
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n, tmp1, tmp2;
	    scanf("%d", &n);
	    struct Height arr[n];
	    for(int i=0; i<n; i++)
	    {
	        scanf("%d %d", &tmp1, &tmp2);
	        arr[i].feet = tmp1;
	        arr[i].inches = tmp2;
	    }
	    int res = findMax(arr, n);
	    printf("%d\n", res);
	}
	return 0;
}  // } Driver Code Ends
