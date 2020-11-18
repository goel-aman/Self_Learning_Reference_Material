#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n){
    // you can check for col

    for(int row = 0;row<i;row++){
        if(boar+d[row][j] == 1){
            return false;
        }
    }

    // you can check for left diagonal
    int x = i;
    int y = j;

    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    // you can for right diagonal
    x = i;
    y = j;
    while(x >= 0 && y < n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    // the position is now safe 
    return true;
}


bool solveNQueen(int board[][10],int i,int n){
    // Base case
    if(i == n){
        // /you have successfully place queen in n rows
        // print the board;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        return true;
    }

    // recursive case
    // try to place the queen in the current row and call on the remaining part which  will be solved by recursion
    for(int j=0;j<n;j++){
        // I have to check if i, jth position is safe to place the queen or not
        if(isSafe(board,i,j,n)){
            // Place the queen - assuming i ,j is the right position
            board[i][j] = 1;
            bool nextQueenRakhpaye = solveNQueen(board,i+1,n);
            if(nextQueenRakhpaye){
                return true;
            }
            // Means i,j is not the right position so our assumption is wrong
            board[i][j] = 0; // backtrack
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNQueen(board,0,n);

    return 0;
}