#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc (sizeof(struct Node));

    if (newNode == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node *mergeLists(struct Node *list1, struct Node *list2){
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL){
        if (list1->data <= list2->data){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    }
    else{
        tail->next = list2;
    }

    return dummy.next;
}

void printList(struct Node *head){
    while (head != NULL){
        printf("%d", head->data);
        if (head->next != NULL){
            printf(" -> ");
        }
        head=head->next;
    }
    printf(" -> NULL\n");
}