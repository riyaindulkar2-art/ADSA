#include <iostream>
using namespace std;

// Structure of a tree node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};


Node* insertNode()
{
    int data;

    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node* node = new Node(data);

    cout << "Enter left child of " << data << endl;
    node->left = insertNode();

    cout << "Enter right child of " << data << endl;
    node->right = insertNode();

    return node;
}


void preorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->data << " ";

    preorder(node->left);
    preorder(node->right);
}


void inorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left);

    cout << node->data << " ";

    inorder(node->right);
}


void postorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);

    cout << node->data << " ";
}

int main()
{
    cout << "Create Binary Tree\n";

    Node* root = insertNode();

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}