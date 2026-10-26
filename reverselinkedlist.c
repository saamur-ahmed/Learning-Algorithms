#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next
};

//creating a new node

struct Node* createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// reversing the liked list 
struct Node* reverseList(struct Node *head){

    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;}

//printing

void printlist(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");

}

// free allocated memory

void freeList(struct Node *head){
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

