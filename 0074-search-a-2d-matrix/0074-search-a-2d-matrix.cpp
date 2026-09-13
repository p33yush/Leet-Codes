class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int m = grid.size();
        int n = grid[0].size();

        int low =0;
        int high=m*n-1;
        while(low<=high){
            int mid = low + (high-low)/2;

            int row = mid / n;
            int col = mid % n;

            if(grid[row][col] == target) return true;
            else if(grid[row][col]> target) high=mid-1;
            else low =mid+1;
        }
        return false;
    }
};