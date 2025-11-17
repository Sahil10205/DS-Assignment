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

int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return (left < right ? left : right) + 1;
}

int main() {
    Node* root = NULL;
    root = insert(root, 40);
    insert(root, 20);
    insert(root, 60);
    insert(root, 10);
    insert(root, 30);
    insert(root, 50);

    cout << minDepth(root) << "\n";
    return 0;
}