#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "connect4.h"

// Start the simulation
int main() {

    int board[ROWS][COLUMNS] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Inform the user
    printf("\n Program has started ... \n");

    // Check AI level
    int mode;
    do {
        printf("Select the level of your AI (0-3) \n");
        scanf("%d", &mode);
    } while(!(mode >= 0 && mode <= 3));

    // Display the game board
    display_board_ASCII(board);
    printf("\n");

    int playermove = 0;
    int player = 1;

    while(1) {

        // Ask for move
        printf("\nPlayer %d: Which column do you want to play?\n", player);
        scanf("%d", &playermove);

        // Add player move
        move_board(board, playermove, player);
        if(check_winning(board, playermove) == 1) {
            printf("Player Wins!!\n");
            display_board_ASCII(board);
            return 0;
        }
        else if(check_winning(board, playermove) == 0){
            display_board_ASCII(board);
        }
        else {
            return 0;
        }

        // CPU move
        player = 2;
        int output;
        output = computer_move(board, player, mode);
        add_move(board, output, player);
        if(check_winning(board, playermove) == 2) {
            printf("Computer Wins!!\n");
            display_board_ASCII(board);
            return 0;
        }
        else if(check_winning(board, playermove) == 0) {
            display_board_ASCII(board);
        }
        else {
            return 0;
        }

        player = 1;  // switch back to human
    }

    return 0;
}
