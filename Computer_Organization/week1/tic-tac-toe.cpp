#include <iostream>
using namespace std;
char board[3][3];

void make_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    //system("cls"); 
    cout << "|---|---|---|" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl << "|---|---|---|" << endl;
    }
}

bool check_winner() {
    for (int i = 0; i < 3; i++) { //가로세로
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
            return true;
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
            return true;
    }
    return false;

}

int main() {
    int x, y;
    int k = 0;
    make_board();
    
    while (1) {
        
        print_board();
        cin >> x >> y;
        if (board[x][y] != ' ') {
            cout << "Please place it elsewhere" << endl;
            continue;
        } else if (x > 2 || y > 2) {
            cout << "Please enter a number from 0 to 2" << endl;
            continue;
        }
        board[x][y] = (k % 2 == 0) ? 'X' : 'O';
        k++;

        if (check_winner()) {
            print_board();
            cout << "End" << endl;
            break;
        }
        
        
    }


    return 0;
}