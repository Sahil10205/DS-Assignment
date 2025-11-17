#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node nodes[100];
int nodeCount = 0;

Node* create(int val) {
    nodes[nodeCount].data = val;
    nodes[nodeCount].left = NULL;
    nodes[nodeCount].right = NULL;
    return &nodes[nodeCount++];
}

Node* insert(Node* root, int val) {
    if (root == NULL) return create(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int main() {
    Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    cout << findMin(root) << "\n";
    return 0;
}