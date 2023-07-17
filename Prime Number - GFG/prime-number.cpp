//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
      if (N <= 1) {
        return false; // 0 and 1 are not prime numbers
    }

    if (N <= 3) {
        return true; // 2 and 3 are prime numbers
    }

    if (N % 2 == 0 || N % 3 == 0) {
        return false; // Numbers divisible by 2 or 3 (except 2 and 3 themselves) are not prime
    }

    // Check for factors from 5 to the square root of N (considering only odd numbers)
    for (int i = 5; i * i <= N; i += 6) {
        if (N % i == 0 || N % (i + 2) == 0) {
            return false; // N is divisible by i or i+2, so it is not a prime number
        }
    }

    return true; // N is only divisible by 1 and itself, so it is a prime number
}

};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends