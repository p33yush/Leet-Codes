class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> rots;
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) cnt++;
                if(grid[i][j] == 2){
                    rots.push({i,j});
                }
            }
        }

        vector<int> dirs = {-1,0,1,0,-1};

        for(int min = 1;!rots.empty() && cnt>0;min++){
            int sz = rots.size();
            for(int i=0;i<sz;i++){
                int curRow = rots.front().first;
                int curCol = rots.front().second;
                rots.pop();
                for(int d = 0;d<dirs.size()-1;d++){
                    int nextRow = curRow + dirs[d];
                    int nextCol = curCol + dirs[d+1];

                    if(nextRow>=0 && nextRow<row && nextCol>=0 && nextCol<col && grid[nextRow][nextCol] == 1){
                        grid[nextRow][nextCol] = 2;
                        rots.push({nextRow,nextCol});

                        if(--cnt == 0){
                            return min;
                        }
                    }
                }
            }
        }
        return cnt>0?-1:0;
    }

};