class Solution {
public:
    bool checkFunc(vector<vector<char> >&board, int x, int y , char ch){
        for(int i=0;i<9;i++){
            if( board[i][y]==ch || board[x][i]==ch || board[( (x/3) *3) + (i/3)][( (y/3) * 3) + (i%3)]==ch )
                return false;

        }
        return true;
    } 
    bool solveSudokuHelper(vector<vector<char> > &board){
        for(int i=0;i<9;i++){
            for(int j=0 ;j<9;j++){
                if(board[i][j] == '.'){
                    for(char ch='1';ch<='9'; ch++){
                        
                        if(checkFunc(board,i,j,ch)){
                            board[i][j] = ch;

                            if( solveSudokuHelper(board) )
                                return true;
                            
                             board[i][j]='.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};
