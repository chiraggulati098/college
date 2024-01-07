#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void insertNode(struct Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }

    if (root->left == NULL) {
        root->left = new Node(val);
    } else if (root->right == NULL) {
        root->right = new Node(val);
    } else {
        if (rand() % 2 == 0) {
            insertNode(root->left, val);
        } else {
            insertNode(root->right, val);
        }
    }
}

void deleteNode(struct Node* root, int val) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL && root->left->data == val) {
        delete root->left;
        root->left = NULL;
        return;
    }

    if (root->right != NULL && root->right->data == val) {
        delete root->right;
        root->right = NULL;
        return;
    }

    deleteNode(root->left, val);
    deleteNode(root->right, val);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Original Tree (postorder): ";
    postorder(root);
    cout << endl;

    insertNode(root, 8);
    deleteNode(root, 4);
    cout << "Tree after operating (postorder): ";
    postorder(root);
    cout << endl;

    return 0;
}