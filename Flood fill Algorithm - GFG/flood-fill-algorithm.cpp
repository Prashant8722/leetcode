//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int r = image.size();   // number of rows
        int c = image[0].size(); //// number of column
        
       
         int match = image[sr][sc];
    
        
        if (match == newColor) {
        // If the starting point already has the newColor, no need to perform flood fill
        return image;
    }
        queue<pair<int , int>>q;
        
        q.push({sr , sc});
        
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
        
        while(!q.empty()){
            pair<int , int > curr  = q.front();
            
            int row = curr.first;
            int col = curr.second;
            
            q.pop();
            
            
              if (image[row][col] != match) {
            // If the current pixel doesn't match the starting color, continue to the next iteration
            continue;
        }
            
            image[row][col] = newColor;
            
            for (const auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            
            if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c && image[newRow][newCol] == match) {
                q.push({newRow, newCol});
            }
            
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends