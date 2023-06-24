//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
/*
Initialize two variables flips1 and flips2 to 0. These variables will represent the number of flips needed if the string starts with '0' and '1', respectively.
Iterate through the characters in the string s using a loop:
For each character at index i, determine the expected character based on the index. If i is even, the expected character should be '0'; otherwise, it should be '1'.
Compare the current character at index i with the expected character. If they are different, increment flips1 by 1; otherwise, increment flips2 by 1.
*/
    int flips1 = 0;
    int flips2 = 0;
    for (int i = 0; i < s.length(); i++) {
        char expectedChar = (i % 2 == 0) ? '0' : '1';
        if (s[i] != expectedChar) {
            flips1++;
        } else {
            flips2++;
        }
    }
    return min(flips1, flips2);
}