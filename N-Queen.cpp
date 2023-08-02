#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
      if(board[i][col] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if(board[i][j] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
      if(board[i][j] == 1) return false;
    }
    return true;
}

void prettyPrint(vector<vector<int>> &board) {

    for (int i = 0; i < board.size(); i++) {
        cout << endl;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 1) cout << "Q ";
            else cout <<  "* ";
        }
    }
    cout<<endl;
}

bool solveNQueen(vector<vector<int>> &board, int i, int n, int &count) {
    if(i == n) {
      prettyPrint(board);
      count++;
      return true;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, i, j, n)) {
            board[i][j] = 1;
            bool isNextSafeToPlace = solveNQueen(board, i + 1, n, count);

            board[i][j] = 0;
        }
    }

    return false;
}

int main() {

    cout << "\nThis program finds out positions of N - Queens.\n" << endl;
    int size, queens;
    cout << "Enter the size of chess board : \n";
    cin >> size;

    int count = 0;

    vector<vector<int>> board(size, vector<int>(size, 0));

    solveNQueen(board, 0, size, count);

    cout<<endl<<count<<endl;
    return 0;
}
