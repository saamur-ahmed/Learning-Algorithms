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

void freeList(struct Node *head){
    while (head != NULL){
        struct Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void){
    struct Node *list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node *list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    //merging bom it shld work
    struct Node *merged = mergeLists(list1,list2);

    printf("Merging done\n");
    printList(merged);
    freeList(merged);
    return 0;

}