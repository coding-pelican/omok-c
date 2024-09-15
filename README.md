# Omok

A simple implementation of the Omok (Five in a Row) game in C.

## Overview

This project implements the classic Omok game, also known as Gomoku or Five in a Row. The game is played on a grid where
two players take turns placing their stones, aiming to get five in a row horizontally, vertically, or diagonally.

## Features

- Console-based interface
- 15x15 game board
- Two-player gameplay
- Win detection in all directions

## Getting Started

### Prerequisites

- C compiler (e.g., GCC, Clang, or MSVC)

### Building and Running

1. Clone the repository:

```shell
git clone https://github.com/coding-pelican/omok-c.git
```

2. Navigate to the project directory:

```shell
cd omok-c
```

3. Compile the source code:

```shell
clang main.c omok.c -o omok
```

4. Run the game:

```shell
./omok
```

## Gameplay

Players take turns placing their stones on the board. The first player to get five stones in a row wins the game.

## Code Structure

The project consists of the following files:

- `main.c`: Entry point of the program
- `omok.c`: Main game logic implementation
- `omok.h`: Header file with function declarations and constants
- `README.md`: This readme file providing an overview of the project

## Future Improvements

- Add AI opponent
- Implement game saving/loading
- Enhance user interface

## License

This project is released under the MIT License. See the [LICENSE](README.md) file for more details.

## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a
pull request.

## Contact

For any questions or inquiries, please contact the project author:
- Name: Gyeongtae Kim
- Email: <codingpelican@gmail.com>

Enjoy playing Omok!
