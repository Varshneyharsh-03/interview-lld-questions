#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
    private:
    vector<vector<char>> board;
    int current_player;

    public:
    TicTacToe(){
        board = vector<vector<char>> (3,vector<char>(3,' '));
        current_player=1;
    }

    void printBoard()
    {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i < 2) {
                cout << "---------" << endl;
            }
        }
    }


    bool isBoardFull()
    {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }


    bool makeMove(int row,int col){
        if(row>=0 and col>=0 and row<3 and col<3 and board[row][col]==' '){
            if(current_player==1){
                board[row][col] = 'X';
                current_player =2;
            }
            else{
                board[row][col] = 'O';
                current_player = 1;
            }
            return true;
        }
        else{
            return false;
        }
    }

    bool checkWinner(){
        //row and col checking 
        for(int i=0;i<3;i++){
            if(board[i][0]!=' '){
                if(board[i][0]==board[i][1] and board[i][1] == board[i][2]) return true;
            }

            if(board[0][i]!=' '){
                if(board[0][i] == board[1][i] and board[1][i] == board[2][i]) return true;
            }
        }
        //diagonal checking
        if(board[0][0]!=' '){
            if(board[0][0]== board[1][1] and board[1][1]==board[2][2]) return true;
        }

        if(board[0][2]!=' '){
             if(board[0][2]== board[1][1] and board[1][1]==board[2][0]) return true;
        }


        return false;
    }

    int getCurrentPlayer(){
        return current_player;
    }

    
};

int main() {
        TicTacToe game;
        int row , col;

        while(game.isBoardFull() == false and game.checkWinner()==false){
            game.printBoard();
            cout << "Player " << game.getCurrentPlayer()<< ", enter your move (row and column): ";
            cin >> row >> col;

            if(game.makeMove(row,col)){
                cout << "Move successful!" << endl;
            }
            else{
                cout << "Invalid move. Try again." << endl;
            }
        }
        game.printBoard();

        if(game.checkWinner()){

             cout << "Player " << (3 - game.getCurrentPlayer())
             << " wins!" << endl;
        
        }
        else{
            cout<<"its a draw"<<endl;
        }
    
    return 0;
}
