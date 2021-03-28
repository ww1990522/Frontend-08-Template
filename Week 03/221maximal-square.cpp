class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;
        int w = matrix.size(), h = matrix[0].size();

        for(int i=0; i<w; i++)
            for(int j=0;j<h;j++){
                if(matrix[i][j]=='0') continue;
                int cur_max = 1;
                int target_i = i+1, target_j = j+1;
                while(w>target_i && h>target_j){
                    int begin_row = target_i-cur_max;
                    int begin_col = target_j-cur_max;
                    bool stop=false;
                    while(begin_row <= target_i){
                        if(matrix[begin_row][target_j]=='0'){
                            stop = true;
                            break;
                        }
                        begin_row++; 
                    }
                    if(stop) break;
                    while(begin_col <= target_j){
                        if(matrix[target_i][begin_col]=='0'){
                            stop = true;
                            break;
                        }
                        begin_col++;
                    }
                    if(stop) break;
                    cur_max++;
                    target_i++;
                    target_j++;
                }
                if(cur_max>max) max = cur_max;
            }
        return max*max;
        
    }
};