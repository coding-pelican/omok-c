/**
 * @file omok.h
 * @author Gyeongtae Kim(dev-dasae) <codingpelican@gmail.com>
 *
 * @brief Omok game header file.
 * @details This file contains the declarations of the functions and types used in the Omok game.
 *
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#ifndef OMOK_H
#define OMOK_H

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)


#include <stdbool.h>


#pragma region Point
/**
 * @brief Represents a 2D point with integer coordinates.
 */
typedef struct Point Point;
struct Point {
    int x;
    int y;
};
#pragma endregion // Point

#pragma region Board
/**
 * @brief The size of the Omok game board.
 * @details The Omok game board is a square grid with a size of 15x15 cells.
 */
#define Board_kSize (15)

/**
 * @brief Represents the Omok game board.
 * @details The Board struct encapsulates the state of the Omok game board, which is a 15x15 grid of cells.
 */
typedef struct Board Board;
struct Board {
    char grid[Board_kSize][Board_kSize];
};

/**
 * @brief Initializes the Omok game board.
 * @param board Pointer to the Board struct to be initialized.
 * @details This function sets all the cells in the game board to an empty state.
 */
void Board_init(Board* board);
/**
 * @brief Checks if the given move is valid on the Omok game board.
 * @param board Pointer to the Board struct representing the game board.
 * @param point The Point struct representing the move to be checked.
 * @return true if the move is valid, false otherwise.
 * @details This function checks if the cell at the given point on the game board is empty, and therefore a valid move.
 */
bool Board_isValidMove(Board* board, Point point);
/**
 * @brief Checks if the Omok game board has a winner after the given move.
 * @param board Pointer to the Board struct representing the game board.
 * @param point The Point struct representing the move to be checked.
 * @return true if the move results in a winning board state, false otherwise.
 * @details This function checks if the player's move at the given point results in a winning board configuration, i.e., 5 consecutive pieces of the same player's color.
 */
bool Board_hasWinner(Board* board, Point point);
/**
 * @brief Prints the current state of the Omok game board.
 * @param board Pointer to the Board struct to be printed.
 * @details This function prints the contents of the Omok game board to the console, with each cell represented by a character ('X', 'O', or '.').
 */
void Board_print(Board* board);
#pragma endregion // Board


#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif // !OMOK_H
