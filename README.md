# Conways-Game-of-Life
A C++ code depicting a iteration of Conway's game of life. The output shows initial and the final matrix. Can be done in a loop to view further iterations.

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
