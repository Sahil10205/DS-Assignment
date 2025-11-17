#include <stdio.h>

int main() {
    int m = 3, n = 3;

    int cost[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int dist[3][3];
    int visited[3][3];

    int i = 0, j = 0;

    while (i < m) {
        j = 0;
        while (j < n) {
            dist[i][j] = 999999;
            visited[i][j] = 0;
            j++;
        }
        i++;
    }

    dist[0][0] = cost[0][0];

    while (1) {
        int minDist = 999999;
        int x = -1, y = -1;

        i = 0;
        while (i < m) {
            j = 0;
            while (j < n) {
                if (visited[i][j] == 0 && dist[i][j] < minDist) {
                    minDist = dist[i][j];
                    x = i;
                    y = j;
                }
                j++;
            }
            i++;
        }

        if (x == -1 && y == -1) break;

        visited[x][y] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        i = 0;
        while (i < 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (visited[nx][ny] == 0) {
                    int newDist = dist[x][y] + cost[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                    }
                }
            }
            i++;
        }
    }

    printf("%d\n", dist[m-1][n-1]);

    return 0;
}