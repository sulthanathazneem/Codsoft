#include<iostream>
#include<vector>
using namespace std;

void displayBoard(const vector<vector<char>>& board)
{
    cout<<"\n";
    for(int i=0;i<3;++i){
        cout<<" ";
        for(int j=0;j<3;++j){
            cout<<board[i][j];
            if(j<2) cout<<" | ";
        }
        cout<<"\n";
        if(i<2) cout<<"---+---+---\n";
    }
    cout<<"\n";
}

void getMove(vector<vector<char>>& board,char player){
    int row,col;
    while(true){
        cout<<"Player "<<player<<", enter your move (row and column: 1 1 for top-left): ";
        cin>>row>>col;
        row--,col--;
        if(board[row][col]==' '){
            board[row][col]=player;
            break;
        }else{
            cout<<"Invalid move! Please try again.";
        }
    }
}

char switchPlayer(char player){
    return player=='X'?'O':'X';
}

bool checkWin(const vector<vector<char>>& board,char player){
    for(int i=0;i<3;++i){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;
    }
    for(int i=0;i<3;++i){
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

bool checkDraw(const vector<vector<char>>& board){
    for(int i=0; i<3 ; i++)
        for(int j=0; j<3 ;j++)
            if(board[i][j]==' ')
                return false;

    return true;
}

int main(){
    char choice;

    do{
        vector<vector<char>> board(3, vector<char>(3,' '));
        bool gameOver=false;
        char currentPlayer='X';

        while(!gameOver){
            displayBoard(board);
            getMove(board, currentPlayer);

            if (checkWin(board,currentPlayer)){
                displayBoard(board);
                cout<<"Player "<<currentPlayer<<" wins!\n";
                gameOver=true;
            }else if(checkDraw(board)){
                displayBoard(board);
                cout<<"The game is a draw!\n";
                gameOver=true;
            }else{
                currentPlayer=switchPlayer(currentPlayer);
            }
        }
        cout<<"Do you want to play again?[Y/N]: ";
        cin>>choice;
    }while(choice=='Y' || choice=='y');
    
    cout<<"Thanks for playing!";
    return 0;
}