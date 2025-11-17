#include <iostream>
using namespace std;

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unite(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, e;
    int u, v, w;
    int cost = 0;
    int edges[100][3];

    cin >> n >> e;
    for (int i = 0; i < e; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp0 = edges[j][0];
                int temp1 = edges[j][1];
                int temp2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp0;
                edges[j + 1][1] = temp1;
                edges[j + 1][2] = temp2;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        if (find(u) != find(v)) {
            unite(u, v);
            cost += w;
            cout << u << " " << v << " " << w << endl;
        }
    }

    cout << "Total cost: " << cost << endl;
    return 0;
}