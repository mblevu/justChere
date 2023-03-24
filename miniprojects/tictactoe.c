#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/**
 * initialize board
 * display board function
 * player turn function
 * computer turn function
 * check winner function
*/
char check_winner();

char board[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';
char computer = 'O';

void display_board() {
    printf("\n   1   2   3 \n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  -----------\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  -----------\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void delay(int seconds)
{
    sleep(seconds);
}

void player_turn()
{
    int row, col;
    printf("\nEnter row (1-3) and column (1-3) to place %c: ",player);
    scanf("%d %d", &row, &col);
    row--;
    col--;
    
    if (board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else 
    {
        printf("Invalid move. Try again.\n");
        player_turn();
    }

    delay(2);
}


void computer_turn()
{
    int row, col;
    printf("Computers turn...\n");
    /** check if comp can win in next turn*/
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col , 3; col++)
        {
            if (board[row][col] == ' ')
            {
                board[row][col] = computer;
                if (check_winner() == computer)
                {
                    return;
                }
                board[row][col] = ' ';
            }
        }
    }

    /** check if player can win in next turn */
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            if (board[row][col] == ' ')
            {
                board[row][col] = player;
                if (check_winner() == player)
                {
                    board[row][col] = computer;
                    return;
                }
                board[row][col] = ' ';
            }
        }
    }
/** play a random move */
    do{
        row = rand() % 3;
        col = rand() % 3;
    }while (board[row][col] != ' ');

    board[row][col] = computer;
}

char check_winner()
{
    int i, j;
/** check rows */
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][1] == board[i][2])
        {
            return (board[i][0]);
        }
    }

    /** check columns */
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return (board[0][i]);
        }
    }

    /** check diagonals */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return (board[0][0]);
    }

    if (board[0][2]  == board[1][1] && board[2][0])
    {
        return (board[0][2]);
    }

    return (' ');
}
 int main()
 {
    int i;
    char winner;

    printf("Tic Tac Toe Game\n");

    srand(time(NULL));

    for (i = 0; i < 9; i++)
    {
        display_board();

        if (player == 'X')
        {
            player_turn();
        }
        else 
        {
            computer_turn();
        }
        
        winner = check_winner();

        if (winner != ' ')
        {
            printf("Winner: %c\n", winner);
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
        computer = (computer == 'O') ? 'O' : 'X';
    }

    if (i == 9)
    {
        printf("Tie game!\n");
    }

    return (0);
 }