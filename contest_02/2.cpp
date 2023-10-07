#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Point {
    int row;
    int col;

    Point(int r, int c) : row(r), col(c) {}
};

bool is_valid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

bool is_can_exit_from_maze(const std::vector<std::string>& maze, int row, int col) {
    int rows = maze.size();
    int cols = maze[0].size();

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::queue<Point> q;

    if (maze[row][col] == '#' || maze[row][col] == 'E') {
        return false;
    }

    q.push(Point(row, col));

    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (maze[curr.row][curr.col] == 'E') {
            return true;
        }

        visited[curr.row][curr.col] = true;

        for (int i = 0; i < 4; i++) {
            int new_row = curr.row + dr[i];
            int new_col = curr.col + dc[i];

            if (is_valid(new_row, new_col, rows, cols) && !visited[new_row][new_col] && maze[new_row][new_col] != '#') {
                q.push(Point(new_row, new_col));
            }
        }
    }

    return false;
}
int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); 
    
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}
