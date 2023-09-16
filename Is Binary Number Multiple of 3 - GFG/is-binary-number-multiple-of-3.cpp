//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    /*
	    This function works by counting the number of set bits at odd and even 
	    positions in the binary number. If the difference between these counts 
	    is a multiple of 3, then the binary number itself is a multiple of 3.
	    */
	    int evenCount = 0;
	    int oddCount = 0;
	    
	    int len = s.length();
	    //Traverse the binary number from the most significant bit
	    for(int i = len - 1 ; i >= 0 ; i--){
	       // If the current bit is set
	        if(s[i] == '1'){
	           // # If the current bit's position is even, increment the even counter
	            if(i % 2 == 0 )
	                evenCount += 1;
                else{
                    oddCount += 1; // If the current bit's position is odd, increment the odd counterIf the current bit's position is odd, increment the odd counter
                }
	        }
	    }
	   // If the difference between the count of odd set bits and even set bits is a multiple of 3
	    int res = abs(evenCount - oddCount);
	    return res % 3 == 0 ?  1 : 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends