/*
객지 1주차 Report Tic-Tac-Toe
*/
#include <iostream>
using namespace std;
//char board[3][3];

void clear_board(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[][3]) {
    cout << "|---|---|---|" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl << "|---|---|---|" << endl;
    }
}

bool check_winner(char board[][3]) {
    for (int i = 0; i < 3; i++) { //가로세로
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
            return true;
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    } else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
        return true;
    }

    return false;
}

bool check_draw(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool play_again() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;

    if (response == 'y' || response == 'Y') 
        return true;
    else 
        return false;
}

int main() {
    int x, y;
    char board[3][3];
    do {
        clear_board(board);
        int k = 0;
        while (true) {
            print_board(board);
            cin >> x >> y;
            if (x < 0 || x > 2 || y < 0 || y > 2) {
                cout << "Please enter valid numbers from 0 to 2" << endl;
                continue;
            }
            if (board[x][y] != ' ') {
                cout << "Please place it elsewhere" << endl;
                continue;
            }
            board[x][y] = (k % 2 == 0) ? 'X' : 'O';
            k++;

            if (check_winner(board)) {
                print_board(board);
                cout << board[x][y] << " Wins!" << endl;
                break;
                
            } else if (check_draw(board)) {
                print_board(board);
                cout << "It's a draw!" << endl;
                break;
            }
        }
    } while (play_again());
    cout << "Game Over!" << endl;
    return 0;
}