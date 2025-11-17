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

bool isBST(Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

int main() {
    Node* root = create(20);
    root->left = create(10);
    root->right = create(30);
    root->left->left = create(5);
    root->left->right = create(15);
    root->right->left = create(25);
    root->right->right = create(35);

    if (isBST(root, -1000000, 1000000))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}