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

bool searchRecursive(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

bool searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return true;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

int main() {
    Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    int key;
    cin >> key;

    if (searchRecursive(root, key)) cout << "Recursive: Found\n";
    else cout << "Recursive: Not Found\n";

    if (searchNonRecursive(root, key)) cout << "Non-Recursive: Found\n";
    else cout << "Non-Recursive: Not Found\n";

    return 0;
}