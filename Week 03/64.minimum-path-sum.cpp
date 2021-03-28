class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //int res[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sub = 0;
                if(i == 0 && j == 0)
                    sub = 0;
                else if(i == 0 && j > 0)
                    sub =  grid[i][j-1];
                else if(i > 0 && j == 0)
                    sub =  grid[i-1][j];
                else   
                    sub = min(grid[i][j-1], grid[i-1][j]);  
                grid[i][j] = grid[i][j] + sub;
            }
        }
        return grid[m-1][n-1];
    }
};