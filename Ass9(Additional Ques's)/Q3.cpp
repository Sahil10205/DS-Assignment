#include <stdio.h>

int main() {
    int N = 4;
    int K = 2;

    int times[3][3] = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int dist[101];
    int visited[101];
    int graph[101][101];
    int i = 1, j;

    while (i <= N) {
        dist[i] = 999999;
        visited[i] = 0;
        j = 1;
        while (j <= N) {
            graph[i][j] = -1;
            j++;
        }
        i++;
    }

    i = 0;
    while (i < 3) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
        i++;
    }

    dist[K] = 0;

    while (1) {
        int minDist = 999999;
        int node = -1;

        i = 1;
        while (i <= N) {
            if (visited[i] == 0 && dist[i] < minDist) {
                minDist = dist[i];
                node = i;
            }
            i++;
        }

        if (node == -1) break;

        visited[node] = 1;

        i = 1;
        while (i <= N) {
            if (graph[node][i] != -1 && visited[i] == 0) {
                int newDist = dist[node] + graph[node][i];
                if (newDist < dist[i]) {
                    dist[i] = newDist;
                }
            }
            i++;
        }
    }

    int maxTime = 0;
    i = 1;
    while (i <= N) {
        if (dist[i] == 999999) {
            printf("-1\n");
            return 0;
        }
        if (dist[i] > maxTime) {
            maxTime = dist[i];
        }
        i++;
    }

    printf("%d\n", maxTime);
    return 0;
}