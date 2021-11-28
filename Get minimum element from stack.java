/*
You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 3 2 1
Explanation: In the first test case for
query 
push(2)  the stack will be {2}
push(3)  the stack will be {2 3}
pop()    poped element will be 3 the
         stack will be {2}
getMin() min element will be 2 
push(1)  the stack will be {2 1}
getMin() min element will be 1
Your Task:
You are required to complete the three methods push() which take one argument an integer 'x' to be pushed into the stack, pop() which returns a integer poped out from the stack and getMin() which returns the min element from the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

Expected Time Complexity : O(1) for all the 3 methods.
Expected Auixilliary Space : O(1) for all the 3 methods.

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
*/


// { Driver Code Starts
import java.util.*;



class Get_Min_From_Stack
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T>0)
		{
			int q = sc.nextInt();
			GfG g = new GfG();
			while(q>0)
			{
				int qt = sc.nextInt();
				
				if(qt == 1)
				{
					int att = sc.nextInt();
					g.push(att);
					//System.out.println(att);
				}
				else if(qt == 2)
				{
					System.out.print(g.pop()+" ");
				}
				else if(qt == 3)
				{
					System.out.print(g.getMin()+" ");
				}
			
			q--;
			}
			System.out.println();
		T--;
		}
		
	}
}


// } Driver Code Ends


class GfG
{
     int am[] = new int[100];
	 int i = 0 ;
	
	 
	    Stack<Integer> s = new Stack<Integer>();

	    /*returns min element from stack*/
	    int getMin()
	    {
		// Your code here
	    	if ( s.empty()) return -1;
	    	 if ( i > 0 ) return am[i-1];
	    	 return am[i];
	    }
	    
	    /*returns poped element from stack*/
	    int pop()
	    {
		// Your code here	
	    	if ( s.empty()) return -1;
	    	if(i > 0 && s.peek() == am[i-1] ) i--;
	    	return s.pop();
	    }

	    /*push element x into the stack*/
	    void push(int x)
	    {
		// Your code here	s
		if ( s.empty() ) {
	    		am[i] = x;
	    		i++;
	    	}
	     	s.push(x);
	    	if ( i > 0 && am[i-1] > x ) { 
	    		am[i] = x;
	    	i++;	
	    	}
	        
	    }
}
