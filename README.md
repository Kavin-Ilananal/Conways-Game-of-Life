# Conways-Game-of-Life
A C++ code depicting a iteration of Conway's game of life. The output shows the matrix after each iteration.

The Game of Life is a cellular automaton devised by mathematician John Conway. It consists of a 2D grid of cells where each cell can either be alive or dead. The state of the board evolves generation by generation according to a fixed set of rules based on neighboring cells.

Rules
1. Any live cell with fewer than 2 live neighbors dies.
2. Any live cell with 2 or 3 live neighbors survives.
3. Any live cell with more than 3 live neighbors dies.
4. Any dead cell with exactly 3 live neighbors becomes alive.

The implementation computes the number of live neighbors for every cell and generates the next state of the board accordingly.

Time Complexity
1. Time: O(m × n)
2. Space: O(m × n)

where m and n are the dimensions of the board.

# Instructions to run the code:

The initial Game of Life board is hardcoded inside main.cpp.
Example:
vector<vector<int>> board = {
    {0,1,0},
    {0,0,1},
    {1,1,1},
    {0,0,0}
};

1. 1 represents a live cell
2. 0 represents a dead cell

You can modify this matrix to test different starting patterns and behaviors.
And just run it in any c++ compiler.
# Iterations
The program also allows the user to enter the number of iterations (generations) to simulate.

For each iteration:

1. The next generation of the board is computed
2. The updated board is displayed as output

This makes it possible to observe how patterns evolve over time.
