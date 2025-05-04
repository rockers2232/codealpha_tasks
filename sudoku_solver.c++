#include <iostream>
using namespace std;

#define N 9

bool isSafe(int board[N][N], int row, int col, int num) {
   
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            return false;

    
    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int board[N][N]) {
    int row = -1, col = -1;
    bool emptyLeft = false;

    for (int i = 0; i < N && !emptyLeft; i++) {
        for (int j = 0; j < N && !emptyLeft; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                emptyLeft = true;
            }
        }
    }

    if (!emptyLeft)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(int board[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board))
        printBoard(board);
    else
        cout << "No solution exists" << endl;

    return 0;
}
