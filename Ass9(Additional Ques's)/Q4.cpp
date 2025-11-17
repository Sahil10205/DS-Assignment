#include <stdio.h>

int grid[3][3] = {
    {1, 1, 0},
    {0, 1, 0},
    {1, 0, 1}
};

int visited[3][3];
int m = 3, n = 3;

void dfs(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return;
    if (grid[x][y] == 0 || visited[x][y] == 1) return;

    visited[x][y] = 1;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    int i = 0, j, count = 0;

    while (i < m) {
        j = 0;
        while (j < n) {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }

    i = 0;
    while (i < m) {
        j = 0;
        while (j < n) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                dfs(i, j);
                count++;
            }
            j++;
        }
        i++;
    }

    printf("%d\n", count);
    return 0;
}