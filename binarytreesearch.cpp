#include <iostream>
using namespace std;

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


Node* createTree()
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
    node->left = createTree();

    cout << "Enter right child of " << data << endl;
    node->right = createTree();

    return node;
}


void preorder(Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}


void inorder(Node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}


bool search(Node* node, int key)
{
    if (node == NULL)
    {
        return false;
    }

    if (node->data == key)
    {
        return true;
    }

    return search(node->left, key) ||
           search(node->right, key);
}

int main()
{
    Node* root;

    cout << "Create Binary Tree\n";
    root = createTree();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    int key;

    cout << "\n\nEnter key to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Key found";
    else
        cout << "Key not found";

    return 0;
}