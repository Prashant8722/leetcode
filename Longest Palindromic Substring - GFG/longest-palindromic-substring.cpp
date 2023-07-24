//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
/*
Algorithm:

Initialize a 2D array dp of size n x n, where n is the length of the input string s. This array will be used to store whether a substring from index i to index j is a palindrome or not.

Initialize two variables start and end to keep track of the starting and ending indices of the longest palindrome substring found so far. Initialize both start and end to 0 initially.

Iterate over the indices of the input string s with two nested loops. The outer loop (i) represents the fixed ending position of the substring, and the inner loop (j) represents the starting position of the substring. We traverse the string in the upper triangular matrix of the dp array to avoid recomputation of already solved subproblems.

Within the nested loops, check for three conditions to determine if the substring from index i to index j is a palindrome:

If i == j, it means it is a single character, and thus, it is a palindrome (set dp[i][j] = 1).
If i - j == 1, it means it is a substring of length 2. Check if the characters at indices i and j are the same. If they are, it is a palindrome (set dp[i][j] = 1).
If s[i] == s[j] (the characters at the border of the substring are the same), and dp[i-1][j+1] (the substring inside the border) is also a palindrome, then the entire substring from i to j is a palindrome (set dp[i][j] = 1).
While calculating the palindromes, update start and end whenever a longer palindrome is found.

Finally, return the substring of s from index start to index end (inclusive), which represents the longest palindrome substring.
*/
class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        int n = s.length(); //length of string
        if(n == 1) return s;    // only 1 length string return that string
        int dp[n][n] =  {0};
        int start = 0 , end = 0; //it tells starting and ending index of longrst substring
        
        //i fixed end position of s for upper tringular matrix dp
        for(int i = 0 ; i < n ; i++){
            //j fixed start position in s
            for(int j = i ; j >= 0; j--){   
                if(i == j) dp[i][j] =1; //Diagonal filled it represents only one length of substring always;
                
                else if(i - j == 1){ //for a string of length 2 in upper triangular matrix
                    if(s[i] == s[j]) dp[i][j] = 1;
                }
                
                else if(s[i] == s[j] and dp[i - 1][j+1] == 1){   //border character and substring inside border indicating by i and j
                    dp[i][j] = 1;
                }
                //tracking maximum length for substring with index in s
                if(dp[i][j] ==1 and i - j > end -start){
                    start = j ;
                    end = i;
                }
            }
        }
        return s.substr(start ,end - start + 1);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends