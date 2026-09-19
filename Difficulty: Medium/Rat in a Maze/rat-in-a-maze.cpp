class Solution {
  public:
    bool isValid(int i,int j,vector<vector<int>>& maze, int n,vector<vector<bool>>& vis){
        if(i>=n|| i<0 ||j<0 || j>=n) return false;
        if(maze[i][j]==0) return false;
        if(vis[i][j]==true) return false;
        return true;
    }
    
    void solve(int i,int j,vector<vector<int>>& maze,int n,vector<string>& ans,string& s,vector<vector<bool>>& vis){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        vis[i][j]=true;
        
            //up
            if(isValid(i-1,j,maze,n,vis)){
                s.push_back('U');
                
                solve(i-1,j,maze,n,ans,s,vis);
                
                s.pop_back();
            }
            //down
            if(isValid(i+1,j,maze,n,vis)){
                s.push_back('D');
                
                solve(i+1,j,maze,n,ans,s,vis);
                
                s.pop_back();
            }
            
            //left
            if(isValid(i,j-1,maze,n,vis)){
                s.push_back('L');
                
                solve(i,j-1,maze,n,ans,s,vis);
                
                s.pop_back();
            }
            
            //right
            if(isValid(i,j+1,maze,n,vis)){
                s.push_back('R');
                
                solve(i,j+1,maze,n,ans,s,vis);
                
                s.pop_back();
            }
        
        vis[i][j]=false;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        vector<string> ans;
        int n=maze.size();
        if (n==0 || maze[0][0] == 0 || maze[n-1][n-1] == 0) {
            return ans;
        }
                
        string s="";
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(0,0,maze,n,ans,s,vis);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};