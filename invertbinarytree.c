#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// invert the binary tree (mirror)
void mirror(Node* root) {
    if (root == NULL)
        return;

    // Invert left and right subtrees first
    mirror(root->left);
    mirror(root->right);

    // Swap left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// print the tree level by level
void levelOrder(Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    Node* queue[100];  // fixed size queue for demo
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;  // number of nodes at this level

        for (int i = 0; i < levelSize; i++) {
            Node* curr = queue[front++];

            if (curr) {
                printf("%d ", curr->data);
                queue[rear++] = curr->left;
                queue[rear++] = curr->right;
            } else {
                printf("N ");  // indicates null child
            }
        }
        printf("\n");  // new line after finishing the level
    }
}

// Driver code for testing
int main() {
    /* in this driver we will construct the following tree:
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Original tree (level order):\n");
    levelOrder(root);

    mirror(root);

    printf("Mirrored tree (level order):\n");
    levelOrder(root);

    return 0;
}