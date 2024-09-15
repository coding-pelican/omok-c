/**
 * @file main.c
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Main entry point for the Omok game.
 * @details This file contains the main function that initializes the Omok game and starts the game loop.
 *
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#include "omok.h"
#include <stdio.h>


int main() {
    Board board = { 0 };
    Board_init(&board);

    char current_player = 'X';

    while (true) {
        Board_print(&board);

        printf("Player %c's turn.\n", current_player);
        printf("Enter the row and column (0-14) separated by a space: ");

        Point move = { 0 };
        (void)scanf("%d %d", &move.x, &move.y);

        if (!Board_isValidMove(&board, move)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board.grid[move.x][move.y] = current_player;

        if (Board_hasWinner(&board, move)) {
            Board_print(&board);
            printf("Player %c wins!\n", current_player);
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    return 0;
}
