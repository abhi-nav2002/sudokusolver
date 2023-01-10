#include <iostream>
#include<bits/stdc++.h>

using namespace std;
    bool checkifcorrect(vector<vector<char>> &board, int row, int col, char val){
        for(int i=0; i<9; i++){
            if(board[row][i] == val )
                return false;
            if(board[i][col] == val)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        int n = board[0].size();
        char c;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(board[i][j] == '.'){
                    
                    for(char val = '1'; val <= '9'; val++){
                        
                        if(checkifcorrect(board,i,j,val)){
                            board[i][j]=val;
                            
                            bool ifsolpossible = solve(board);
                            if(ifsolpossible)
                                return true;
                            else
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
        solve(board);
           
    }

int main()
{
    vector<vector<char>> board(9,vector<char> (9,'.'));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            char a;
            cin>>a;
            board[i][j]=a;
        }
    }
    solveSudoku(board);
    cout<<"\n";
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
//for a reference you can use the below input
/*"5","3",".",".","7",".",".",".","."
"6",".",".","1","9","5",".",".","."
".","9","8",".",".",".",".","6","."
"8",".",".",".","6",".",".",".","3"
"4",".",".","8",".","3",".",".","1"
"7",".",".",".","2",".",".",".","6"
".","6",".",".",".",".","2","8","."
".",".",".","4","1","9",".",".","5"
".",".",".",".","8",".",".","7","9"*/