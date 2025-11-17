#include <iostream>
using namespace std;

struct Node {
    int data;
    int left;
    int right;
};

Node tree[100];

void preorder(int index) {
    if (index == -1) return;
    cout << tree[index].data << " ";
    preorder(tree[index].left);
    preorder(tree[index].right);
}

void inorder(int index) {
    if (index == -1) return;
    inorder(tree[index].left);
    cout << tree[index].data << " ";
    inorder(tree[index].right);
}

void postorder(int index) {
    if (index == -1) return;
    postorder(tree[index].left);
    postorder(tree[index].right);
    cout << tree[index].data << " ";
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val, l, r;
        cin >> val >> l >> r;
        tree[i].data = val;
        tree[i].left = l;
        tree[i].right = r;
    }

    cout << "Pre-order: ";
    preorder(0);
    cout << "\n";

    cout << "In-order: ";
    inorder(0);
    cout << "\n";

    cout << "Post-order: ";
    postorder(0);
    cout << "\n";

    return 0;
}