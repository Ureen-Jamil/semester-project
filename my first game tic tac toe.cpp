#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
bool draw = false;
int row, column;

void display_board()
{
    system("cls");
    cout << "\n\n\n\t\t\t\t  ---W E L C O M E---\n";
    cout << "\n\t\t\t\tT I C \t T A C \t T O E\n";
    cout << "\n\t\t\t\t     ---G A M E---\n";
    cout << "\n\n\n\t\t PLAYER 1 = [X]\n";
    cout << "\n\t\t PLAYER 2 = [0]\n";
    cout << "\t\t\t\t\t|\t\t|\t\n";
    cout << "\t\t\t\t" << board[0][0] << "\t|\t" << board[0][1] << "\t|\t" << board[0][2] << "\n";
    cout << "\t\t\t\t________|_______________|________\n";
    cout << "\t\t\t\t\t|\t\t|\t\n";
    cout << "\t\t\t\t" << board[1][0] << "\t|\t" << board[1][1] << "\t|\t" << board[1][2] << "\n";
    cout << "\t\t\t\t________|_______________|________\n";
    cout << "\t\t\t\t\t|\t\t|\t\n";
    cout << "\t\t\t\t" << board[2][0] << "\t|\t" << board[2][1] << "\t|\t" << board[2][2] << "\n";
    cout << "\t\t\t\t\t|\t\t|\t\n";
}

void resetGame()
{
    turn = 'X';
    draw = false;
    char counter='1';
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = counter++;
        }
    }
}

void player_turn()
{
    char choice;
    if (turn == 'X')
        cout << "\n\n\t\t\t\t PLAYER 1 [X] TURN:";
    else if (turn == '0')
        cout << "\n\n\t\t\t\t PLAYER 2 [0] TURN:";

    cin >> choice;

    if (choice >= '1' && choice <= '9')
    {
        // Valid choice for the Tic-Tac-Toe board
        switch (choice)
        {
        case '1':
            row = 0;
            column = 0;
            break;
        case '2':
            row = 0;
            column = 1;
            break;
        case '3':
            row = 0;
            column = 2;
            break;
        case '4':
            row = 1;
            column = 0;
            break;
        case '5':
            row = 1;
            column = 1;
            break;
        case '6':
            row = 1;
            column = 2;
            break;
        case '7':
            row = 2;
            column = 0;
            break;
        case '8':
            row = 2;
            column = 1;
            break;
        case '9':
            row = 2;
            column = 2;
            break;
        }
    }
    else
    {
        cout << "Invalid choice\n";
        // Add additional handling if needed
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != '0')
    {
        board[row][column] = 'X';
        turn = '0';
    }
    else if (turn == '0' && board[row][column] != 'X' && board[row][column] != '0')
    {
        board[row][column] = '0';
        turn = 'X';
    }
    else
    {
        cout << "BOX IS ALREADY FILLED!\n\tKINDLY CHOOSE ANOTHER NUMBER";
        player_turn();
    }
    display_board();
}

bool gameover()
{
    // check win
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][0] == board[2][0])
            return false;
    }

    // if there is any box not filled
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != '0')
                return true;
        }
    }

    // draw
    draw = true;
    return false;
}

int main()
{
    char playAgain;

    do
    {
	
        while (gameover())
        {
            display_board();
            player_turn();
            gameover();
        }
        if (turn == 'X' && draw == false)
            cout << "\t\t\t\tPLAYER 2 [0] WINS!! CONGRATULATIONS\n";
        else if (turn == '0' && draw == false)
            cout << "\t\t\t\tPLAYER 1 [X] WINS!! CONGRATULATIONS\n";
        else
            cout << "\t\t\t\tGAME DRAW !!\n";

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y')
        {
         
            resetGame();
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
