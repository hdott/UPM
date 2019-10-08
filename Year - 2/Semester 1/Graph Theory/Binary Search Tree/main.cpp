// #include <iostream>
#include <list>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Function to print level order traversal of given binary tree
void levelOrderTraversal(Node* root)
{
    // create an empty queue and enqueue root node
    list<Node*> queue;
    queue.push_back(root);

    // pointer to store current node
    Node* curr = nullptr;

    // run till queue is not empty
    while (queue.size())
    {
        // process each node in queue and enqueue their
        // non-empty left and right child to queue
        curr = queue.front();
        queue.pop_front();

        cout << curr->key << " ";

        if (curr->left)
           queue.push_back(curr->left);

        if (curr->right)
           queue.push_back(curr->right);
    }
}

// main function
int main()
{
    Node* root = nullptr;

    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    levelOrderTraversal(root);

    return 0;
}
