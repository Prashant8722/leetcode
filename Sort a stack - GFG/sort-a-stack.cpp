//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   vector<int>vec;
   int stackSize = s.size();
   for(int i  = 0 ; i < stackSize ; i++){
        vec.push_back(s.top());
        s.pop();
}
for(int i = 0 ; i < vec.size() ; i++)
    {
        for(int j = 0 ; j < vec.size()-i-1 ; j++)
            {
                if(vec[j] > vec[j+1])
                    swap(vec[j] , vec[j+1]);
            }
    }
for(int i  = 0 ; i < vec.size() ; i++){
        int x = vec[i];
        s.push(x);
}
return;
}