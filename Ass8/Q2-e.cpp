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
    else
        root->right = insert(root->right, value);
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

Node* getPredecessor(Node* root, Node* target) {
    if (target->left != NULL)
        return findMax(target->left);

    Node* predecessor = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    int key = 10;
    Node* target = search(root, key);
    Node* pred = getPredecessor(root, target);

    if (pred != NULL)
        cout << pred->data << "\n";
    else
        cout << "-1\n";

    return 0;
}