//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        int n = s.length(); //length of string
        if(n == 1) return s;    // only 1 length string return that string
        int dp[n][n] =  {0};
        int start = 0 , end = 0; //it tells starting and ending index of longrst substring
        
        //start position of s for upper tringular matrix dp
        for(int i = 0 ; i < n ; i++){
            //fixed end position in s
            for(int j = i ; j >= 0; j--){   
                if(i == j) dp[i][j] =1; //Diagonal filled it represents only one length of substring always;
                
                else if(i - j == 1){ //for a string of length 2 in upper triangular matrix
                    if(s[i] == s[j]) dp[i][j] = 1;
                }
                
                else if(s[i] == s[j] and dp[i -1][j+1] == 1){   //border character and substring inside border indicating by i and j
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