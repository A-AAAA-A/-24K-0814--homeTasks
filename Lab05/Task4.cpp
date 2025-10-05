#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for(int i=0; i<row; i++)
        if(board[i][col]=='Q') return false;
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        if(board[i][j]=='Q') return false;
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
        if(board[i][j]=='Q') return false;
    return true;
}

void solveNQueensUtil(int n, int row, vector<string>& board, int& count, vector<vector<string>>& solutions) {
    if(row==n) {
        solutions.push_back(board);
        count++;
        return;
    }
    for(int col=0; col<n; col++) {
        if(isSafe(board,row,col,n)) {
            board[row][col]='Q';
            solveNQueensUtil(n,row+1,board,count,solutions);
            board[row][col]='.';
        }
    }
}

void solveNQueens(int n) {
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> solutions;
    int count=0;
    solveNQueensUtil(n,0,board,count,solutions);

    if(!solutions.empty()) {
        cout<<"One valid board configuration:\n";
        for(auto row: solutions[0]) cout<<row<<"\n";
    }
    cout<<"Total number of distinct solutions: "<<count<<endl;
}

int main() {
    int n;
    cout<<"Enter N: ";
    cin>>n;
    solveNQueens(n);
    return 0;
}
