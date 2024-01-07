#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left,*right;

    Node(int val)   {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root)    {
    if (root == NULL)   {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insertBST(Node* root, int val)    {
    if (root == NULL)   {
        return new Node(val);
    }
    if (val < root->data)   {
        root->left = insertBST(root->left,val);
    }   else    {
        root->right = insertBST(root->right,val);
    }
    return root;
}

Node* searchInBST(Node* root, int key)  {
    if (root == NULL)   {
        return NULL;
    }
    if (root->data == key)  {
        return root;
    }
    if (root->data > key)   {
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

Node* inorderSucc(Node* root)   {
    Node* current = root;
    while (current && current->left != NULL)    {
        current = current->left;
    }
    return current;
}

Node* deleteInBST(Node* root, int key)  {
    if (key < root->data)   {
        root->left = deleteInBST(root->left,key);
    }
    else if (key > root->data)   {
        root->right = deleteInBST(root->right,key);
    }
    else    {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right,temp->data);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insertBST(root,50);
    insertBST(root,30);
    insertBST(root,70);
    insertBST(root,20);
    insertBST(root,40);
    insertBST(root,60);
    insertBST(root,80);

    inorder(root);
    cout<<endl;
    root = deleteInBST(root,50);
    inorder(root);

    cout<<endl;

    return 0;
}