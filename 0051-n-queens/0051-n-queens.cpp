class Solution {
public:
    bool canQueenBePlaced(int row, int col, vector<string> &config, int n){
        bool LUD=true, sameRow=true, LLD=true;
        //LUD
        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0){
            if(config[i][j]=='Q'){
                LUD=false;
                break;
            }
            i--;
            j--;
        }
        //LLD
        i=row+1;
        j=col-1;
        while(i<n && j>=0){
            if(config[i][j]=='Q'){
                LUD=false;
                break;
            }
            i++;
            j--;
        }
        //same row
        i=row;
        j=col-1;
        while(j>=0){
            if(config[i][j]=='Q'){
                LUD=false;
                break;
            }
            j--;
        }
        return LUD && sameRow && LLD;
    }
    void NQueen(int col,int n,vector<vector<string>> &result,vector<string> &config){
        //base case
        if(col==n){
            result.push_back(config);
            return;
        }
        //calls recursive
        for(int row=0; row<n; row++){
            if(canQueenBePlaced(row,col,config,n)){
                config[row][col]='Q';
                NQueen(col+1,n,result,config);
                config[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string> config(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            config[i]=s;
        }
        int col=0;
        NQueen(col,n,result,config);
        return result;
    }
};