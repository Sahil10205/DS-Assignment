#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int value) {
    if (root == NULL) return create(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int values[] = {30, 20, 40, 10, 25, 35, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    inorder(root);
    return 0;
}