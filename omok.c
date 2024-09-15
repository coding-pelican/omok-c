/**
 * @file omok.c
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Omok game implementation.
 * @details This file contains the implementation of the Omok game.
 *
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#include "omok.h"
#include <stdio.h>


void Board_init(Board* board) {
    for (int i = 0; i < Board_kSize; ++i) {
        for (int j = 0; j < Board_kSize; ++j) {
            board->grid[i][j] = '.';
        }
    }
}

void Board_print(Board* board) {
    for (int i = 0; i < Board_kSize; ++i) {
        for (int j = 0; j < Board_kSize; ++j) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
}

bool Board_isValidMove(Board* board, Point point) {
    return (0 <= point.x && point.x < Board_kSize) &&
           (0 <= point.y && point.y < Board_kSize) &&
           (board->grid[point.x][point.y] == '.');
}

bool Board_hasWinner(Board* board, Point point) {
    char player = board->grid[point.x][point.y];

    // Check horizontal
    int count = 0;
    for (int j = 0; j < Board_kSize; ++j) {
        if (board->grid[point.x][j] == player) {
            count++;
        } else {
            count = 0;
        }

        if (count == 5) {
            return true;
        }
    }

    // Check vertical
    count = 0;
    for (int i = 0; i < Board_kSize; ++i) {
        if (board->grid[i][point.y] == player) {
            count++;
        } else {
            count = 0;
        }

        if (count == 5) {
            return true;
        }
    }

    // Check diagonal (top-left to bottom-right)
    count = 0;
    int i = point.x - point.y;
    int j = 0;
    if (i < 0) {
        j = -i;
        i = 0;
    }
    while (i < Board_kSize && j < Board_kSize) {
        if (board->grid[i][j] == player) {
            count++;
        } else {
            count = 0;
        }

        if (count == 5) {
            return true;
        }

        i++;
        j++;
    }

    // Check diagonal (top-right to bottom-left)
    count = 0;
    i     = point.x + point.y;
    j     = 0;
    if (Board_kSize <= i) {
        j = i - Board_kSize + 1;
        i = Board_kSize - 1;
    }
    while (0 <= i && j < Board_kSize) {
        if (board->grid[i][j] == player) {
            count++;
        } else {
            count = 0;
        }

        if (count == 5) {
            return true;
        }

        i--;
        j++;
    }

    return false;
}
