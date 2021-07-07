//Q7. Rat in a Maze

#include <bits/stdc++.h>
using namespace std;


const int POSSIBLE_MOVES = 4;
vector<int> xMoves = {0, 1, 0, -1};
vector<int> yMoves = {1, 0, -1, 0};

bool isSafe(const vector<vector<bool>> &matrix, const vector<vector<bool>> &visited, int x, int y, int row, int col)
{
    if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || !matrix[x][y])
    {
        return false;
    }
    else
    {
        return true;
    }
}


void countPathInMatrixAllDirectionMovementHelper(const vector<vector<bool>> &matrix, vector<vector<bool>> &visited, int x, int y, int row, int col, int &res)
{
    if (x == row - 1 && y == col - 1)
    {
        visited[x][y] = true;
        res++;
    }
    
    if (isSafe(matrix, visited, x, y, row, col)) {
        visited[x][y] = true;
        int nextX, nextY;
        for (int i = 0; i < POSSIBLE_MOVES; i++) {
            nextX = x + xMoves[i];
            nextY = y + yMoves[i];
            countPathInMatrixAllDirectionMovementHelper(matrix, visited, nextX, nextY, row, col, res);
        }
        visited[x][y] = false;
    }
}

int countPathInMatrixAllDirectionMovement(const vector<vector<bool>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return 0;
    int col = matrix[0].size();
    if ((!matrix[0][0]) || (!matrix[row-1][col-1]))
    {
        return 0;
    }
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    int res = 0;
    countPathInMatrixAllDirectionMovementHelper(matrix, visited, 0, 0, row, col, res);
    return res;
}

int main()
{
    vector<vector<bool>> vec =   {{1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,0},
                                 {1,1,1,1}};
    cout<<countPathInMatrixAllDirectionMovement(vec);
    return 0;
}
