#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
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

void printList(struct Node *head) {
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

int main(void){
    struct Node *head = createNode(10);

    if (head == NULL) return 1;

    head->next = createNode(20);
    if(head->next == NULL){
        freeList(head);
        return 1;
    }

    head->next->next = createNode(30);
    if (head->next->next == NULL) freeList(head); return 1;
    

    printf("Original List:\n");
    printList(head);

    head = reverseList(head);
    
    printf("Reversed List:\n");
    printList(head);

    freeList(head);

    return 0;

}