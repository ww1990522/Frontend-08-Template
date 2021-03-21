class Solution {
public:
    vector<vector<string>> res;
    map<int, int> exsited_row_col;   //行 列
    vector<vector<string>> solveNQueens(int n) {
        fun(1, n);
        return res;
    }
    void fun(int cur_row,int n){
        //teminator
        if(cur_row > n){
            save_result(n);
            return;
        }

        for(int cur_col=1; cur_col<=n; cur_col++){           
            if(!check_conflict(cur_row, cur_col)){
                //下探
                insertNewExist(cur_row, cur_col);
                fun(cur_row+1, n);     
                //回溯
                removeExist(cur_row);
            }
        }
    }
    bool check_conflict(int cur_row, int cur_col){
        for(int exist_row = 1; exist_row < cur_row; exist_row++){
            int exsit_col = exsited_row_col[exist_row];
            if(exsit_col == cur_col 
            || cur_row-exist_row == cur_col-exsit_col 
            || cur_row-exist_row == exsit_col-cur_col){
                return true;
            }
        }
        return false;
    }
    void insertNewExist(int row, int col){       
        exsited_row_col[row] = col;
    }
    void removeExist(int row){
        exsited_row_col.erase(row);
    }
    void save_result(int n){
        vector<string> vs;
        for(auto a : exsited_row_col){
            string new_row;
            for(int i = 1; i <= n; i++){
                if(a.second != i)
                    new_row.push_back('.');
                else
                    new_row.push_back('Q');               
            }
            vs.push_back(new_row);
        }
        res.push_back(vs);
    }
};