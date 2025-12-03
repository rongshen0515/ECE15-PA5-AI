#include "connect4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valid_move(int board[ROWS][COLUMNS], int move) {

    // Complete this function
    if(move < 0 || move > COLUMNS - 1) {
        return 0;
    }

    if(board[0][move] != 0) {
        return 0;
    }

    return 1;
}

int add_move_board(int board[][COLUMNS], int move, int player) {

    // Complete this function
    int rowcount = ROWS - 1;
    int win;

    int r;
    for(r = rowcount; r >= 0; r--) {
        if(board[r][move] == 0) {
            board[r][move] = player;
            break;
        }
        else {
            continue;
        }
    }

    printf("Player %d plays at Column %d\n", player, move);
    return 1;
}

int player_move(int board[][COLUMNS]) {

    // Complete this function
    int xmove = 0;

    do{
        printf("Which column do you want to play?\n");
        scanf("%d", &xmove);
    }while(valid_move(board, xmove) == 0);

    return xmove;
}

int computer_move(int board[][COLUMNS], int player, int mode) {

    // Complete this function
    if(mode == 0) {
        int cmove;
        srand(time(NULL));
        cmove = rand() % COLUMNS;
        while(valid_move(board, cmove) == 0) {
            cmove = rand() % COLUMNS;
        }
        return cmove;
    }
    else if(mode == 1) {

        int opponent = (player == 1 ? 2 : 1);
        int ccc, rrr;
        int rr;

        int tempBoard[ROWS][COLUMNS];

        // Try to win
        for(col = 0; col < COLUMNS; col++) {
            if(valid_move(board, col) == 0) {
                continue;
            }

            for(rrr = 0; rrr < ROWS; rrr++) {
                for(ccc = 0; ccc < COLUMNS; ccc++) {
                    tempBoard[rrr][ccc] = board[rrr][ccc];
                }
            }

            for(rr = ROWS - 1; rr >= 0; rr--) {
                if(tempBoard[rr][col] == 0) {
                    tempBoard[rr][col] = player;
                    break;
                }
            }

            if(check_winning(tempBoard, col) == player) {
                if(col != 7) {
                    return col + 1;
                }
                else {
                    return col;
                }
            }
        }

        // Block opponent
        for(col = 0; col < COLUMNS; col++) {
            if(valid_move(board, col) == 0) {
                continue;
            }

            for(rrr = 0; rrr < ROWS; rrr++) {
                for(ccc = 0; ccc < COLUMNS; ccc++) {
                    tempBoard[rrr][ccc] = board[rrr][ccc];
                }
            }

            for(rr = ROWS - 1; rr >= 0; rr--) {
                if(tempBoard[rr][col] == 0) {
                    tempBoard[rr][col] = opponent;
                    break;
                }
            }

            if(check_winning(tempBoard, col) == opponent) {
                if(col != 7) {
                    return col + 1;
                }
                else {
                    return col;
                }
            }
        }

        srand(time(NULL));
        do {
            cmove = rand() % COLUMNS;
        } while(valid_move(board, cmove) == 0);

        return cmove;
    }
    else if(mode == 2) {
        printf("Under Construction");
        return 0;
    }
    else if(mode == 3) {
        printf("Under Construction");
        return 0;
    }
}

int check_winning(int board[][COLUMNS], int last_move) {

    int r, c;
    int player;

    for(r = 0; r < ROWS; r++) {
        for(c = 0; c < COLUMNS; c++) {
            player = board[r][c];
            if(player == 0) {
                continue;
            }

            if(c + 3 < COLUMNS && board[r][c+1] == player && board[r][c+2] == player && board[r][c+3] == player) {
                return player;
            }

            if(r + 3 < ROWS && board[r+1][c] == player && board[r+2][c] == player && board[r+3][c] == player) {
                return player;
            }

            if(r + 3 < ROWS && c + 3 < COLUMNS && board[r][c+1] == player && board[r+2][c+2] == player && board[r+3][c+3] == player) {
                return player;
            }

            if(r + 3 < ROWS && c - 3 >= 0 && board[r][c-1] == player && board[r][c-2] == player && board[r][c-3] == player) {
                return player;
            }
        }
    }

    return 0;
}
