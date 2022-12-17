#include <bits/stdc++.h>
using namespace std;

// Define the dimensions of the maze
#define MAZE_ROWS 10
#define MAZE_COLS 10

// Define the maze as a two-dimensional array of characters
char maze[MAZE_ROWS][MAZE_COLS];

// Define the possible directions for the algorithm to move in
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// Use a depth-first search algorithm to create a path through the maze
void dfs(int x, int y, int visited[MAZE_ROWS][MAZE_COLS]) {
    // Mark the current cell as visited
    visited[x][y] = 1;

    // Loop through each possible direction
    for (int i = 0; i < 4; i++) {
        // Calculate the coordinates of the cell in the current direction
        int a = x + dx[i];
        int b = y + dy[i];

        // Check if the coordinates are within the bounds of the maze
        if (a >= 0 && a < MAZE_ROWS && b >= 0 && b < MAZE_COLS) {
            // Check if the cell has not been visited
            if (visited[a][b] == 0) {
                // Create a path to the cell by removing the wall between them
                maze[x][y] = ' ';
                maze[a][b] = ' ';

                // Recursively search for a path from the cell
                dfs(a, b, visited);
            }
        }
    }
}


// Generate the maze by filling it with walls ('#') and empty spaces (' ')
void generateMaze() {
    // Initialize the maze with walls
    for (int row = 0; row < MAZE_ROWS; row++) {
        for (int col = 0; col < MAZE_COLS; col++) {
            maze[row][col] = '#';
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Choose a random starting cell
    int x = rand() % MAZE_ROWS;
    int y = rand() % MAZE_COLS;

    // Keep track of the cells that have been visited
    int visited[MAZE_ROWS][MAZE_COLS];
    for (int row = 0; row < MAZE_ROWS; row++) {
        for (int col = 0; col < MAZE_COLS; col++) {
            visited[row][col] = 0;
        }
    }

    // Use a depth-first search algorithm to create a path through the maze
    dfs(x, y, visited);
}



// Print the maze to the console
void printMaze() {
    // Loop through each row of the maze
    for (int row = 0; row < MAZE_ROWS; row ++) {
        for (int col = 0; col < MAZE_COLS; col ++)
            cout << maze[row][col];
        cout << endl;
    }
}

int main() {
    generateMaze();
    printMaze();
    return 0;
}