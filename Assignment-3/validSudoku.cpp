// Q9. Valid Sudoku

#include<bits/stdc++.h>
using namespace std;

bool findInRow(vector<vector<char>> board, int row){
    set<char> seen;
    for(int i=0;i<9;i++)
    {
        char ch = board[row][i];
        if(ch!='.'){
            if(seen.insert(ch).second == false)
            {
                return false;
            }
        }
    }
    return true;
}

bool findInCol(vector<vector<char>> board, int col){
    set<char> seen;
    for(int i=0;i<9;i++)
    {
        char ch = board[i][col];
        if(ch!='.'){
            if(seen.insert(ch).second == false)
            {
                return false;
            }
        }
    }
    return true;
    
}

bool findInBox(vector<vector<char>> board, int startRow, int startCol){
    
    set<char> seen;
    for(int row =0; row<3;row++)
    {
        for(int col =0;col<3;col++)
        {
            char ch = board[row+startRow][col+startCol];
            if(ch!='.')
            {
                if(seen.insert(ch).second == false)
                {
                    return false;
                }
                
            }
        }
    }
    return true;
}

bool isValidSudokuHelper(vector<vector<char>> board, int row, int col){
    return findInRow(board,row) && findInCol(board, col) && findInBox(board, row - row%3, col- col%3);  
}


bool isValidSudoku(vector<vector<char>> board){
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(!isValidSudokuHelper(board,i,j))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board = {  { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
                                    { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                                    { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                                    { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                                    { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                                    { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                                    { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                                    { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                                    { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    
    cout << (isValidSudoku(board) ? "YES\n" : "NO\n");
    return 0;
}
