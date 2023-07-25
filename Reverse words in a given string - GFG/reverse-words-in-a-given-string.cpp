//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
      string reverseWords(string s) 
    { 
        string result = "";
        string curr_word = "";
        stack<string> words;
    
        //initially reversing individual words of the given string one by one.
        for (char c : s)
        {
            //if '.' is encountered, we store the word in list.
            if(c == '.')
            {
                words.push(curr_word);
                curr_word = "";
            }
            //else adding the characters in current word in such
            //a way that original words get reversed.
            else
                curr_word += c;
        }
        //storing the last remaining word in list.
        words.push(curr_word);
        
        //now reversing the whole modified string by adding all 
        //the elements of list in a single string in reverse order.
        int n = words.size();
        for (int i = 0; i<=n-1; ++i)
        {
            result += words.top();
            words.pop();
            if(i!=n-1)
                result += '.';
        }
        //returning the result.
        return result;
    } 
};



//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends