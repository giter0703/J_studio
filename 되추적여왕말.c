#include <stdio.h>
#include <stdbool.h>

#define N 4 //체스판 한 행 갯수 또는 한 열 갯수

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // 같은 열에 다른 여왕이 있는지 확인
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // 왼쪽 대각선 위쪽 확인
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // 오른쪽 대각선 위쪽 확인
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int row) {
    if (row >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;

            if (solveNQUtil(board, row + 1))
                return true;

            board[row][i] = 0; // 백트래킹
        }
    }

    return false;
}

bool solveNQ() {
    // N = 8일 때
    // int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 0, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 0, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 0, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 0, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 0, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 0, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 0, 0, 0 } };

    // N = 4일 때
    int board[N][N] = { { 0, 0, 0, 0},
                        { 0, 0, 0, 0},
                        { 0, 0, 0, 0},
                        { 0, 0, 0, 0}};    

    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}
