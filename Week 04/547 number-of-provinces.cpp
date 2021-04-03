class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int res=0;
        vector<int> visited(grid.size());
        for(int i=0;i<grid.size();i++)
            if(visited[i]==0){
                dfs(grid,visited,i);
                visited[i] = 1;
                res++;
            }
        return res;
    }
    void dfs(vector<vector<int>>& grid,vector<int>& visited,int r){
        for(int j = 0; j<grid.size();j++){
            if(grid[r][j]==1 && visited[j]==0){
                visited[j] = 1;
                dfs(grid,visited,j);
            }
        }
    }
};