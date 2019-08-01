// C program for different tree traversals 
#include <iostream> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 

int treeArray[100]; // Achtung, Array hat fixe länge!



void scrollThroughTree(struct Node* node, int counter) {
    if (node == NULL)
        return;

    treeArray[counter-1] = node->data;
    scrollThroughTree(node->left, counter*2);
    scrollThroughTree(node->right, counter*2+1);
}

// folgende spannende Lösung funktioniert, da
// C (und andere Sprachen) das sog. Zweierkomplement
// verwenden:
int is2PowBitwise(int zahl) {
    return (zahl & -zahl) == zahl;
}

void printTree() {
    for (int counter=1; counter<99; ++counter) {
        int data = treeArray[counter-1];
        if (data == 0)
            return;
        cout << data << " ";

        int lineEndNumber = counter + 1;
        if (is2PowBitwise(lineEndNumber))
            cout << "\n";
    }
    
}


/* Driver program to test above functions*/
int main() 
{ 
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    scrollThroughTree(root, 1);
    printTree();
  
    return 0; 
} 