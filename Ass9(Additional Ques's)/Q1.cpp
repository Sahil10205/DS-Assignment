#include <iostream>
using namespace std;

int a[100][100], visited[100];
int v, e;

void dfs(int data) {
    visited[data] = 1;
    for (int i = 0; i < v; i++) {
        if (a[data][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int u, w, count = 0;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> u >> w;
        a[u][w] = 1;
        a[w][u] = 1;
    }
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    for (int i = 0; i < v; i++) {
        if (visited[i] == 0) {
            dfs(i);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}