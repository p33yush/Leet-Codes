class Solution {
public:
    bool isSafe(int i ,int j,vector<string>& board,int n){
        int row=i;
        int col=j;

        //topleft
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')  return false;
            i--;
            j--;
        }

        //botleft
        i=row;j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }

        //left
        i=row;j=col;
        while(j>=0){
            if(board[i][j]=='Q') return false;
            j--;
        }        

        return true;
    }

    void help(int col, vector<string>& board, vector<vector<string>>& ans,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                help(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        help(0,board,ans,n);
        return ans;
    }
};