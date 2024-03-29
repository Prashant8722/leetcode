//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends

int find(int A[], int X) {
    if (X == A[X])
      return X;
    return A[X] = find(A, A[X]);   //path compression is used
}

void unionSet(int A[], int X, int Z) {

    int rep_x = find(A, X);
    int rep_z = find(A, Z);

    if (rep_x == rep_z)
        return;
    else
        A[rep_x] = rep_z;
    }



