#include <iostream>
#include "list.h"

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* head = NULL;
int nodeCount = 0;

int insertFront(int element) {
    node* current = (node*)malloc(sizeof(node));
    if (current) {
        current->data = element;
        current->next = head;
        head = current;
        nodeCount++;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int insertBack(int element) {
    node* current = (node*)malloc(sizeof(node));
    if (current) {
        current->data = element;
        current->next = NULL;
        if (head == NULL) head = current;
        else {
            node* previous = head;
            while (previous->next != NULL) previous = previous->next;
            previous->next = current;
        }
        nodeCount++;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int insertAfterNode(int index, int element) {
    if (index < 0) return EXIT_FAILURE;
    if (index == 0) return insertFront(element);
    node* previous = head;
    for (int i = 0; i < index; i++) {
        if (previous == NULL) return EXIT_FAILURE;
        previous = previous->next;
    }
    node* current = (node*)malloc(sizeof(node));
    if (current) {
        current->data = element;
        current->next = previous->next;
        previous->next = current;
        nodeCount++;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int deleteFront() {
    if (head != NULL) {
        node* current = head;
        head = head->next;
        free(current);
        nodeCount--;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int deleteBack() {
    if (nodeCount == 1) return deleteFront();

    node* previous = NULL;
    node* current = head;
    if (!current) return EXIT_FAILURE;

    while (current->next) {
        previous = current;
        current = current->next;
    }
    if (!previous) return EXIT_FAILURE;
    previous->next = NULL;
    nodeCount--;
    free(current);
    return EXIT_SUCCESS;
}

int deleteNode(int index) {
    if (index > nodeCount || index <= 0) return EXIT_FAILURE;
    if (index == 1) return deleteFront();

    node* previous = NULL;
    node* current = head;
    for (int i = 0; i < index - 1; i++) {
        previous = current;
        current = current->next;
    }
    if (!previous) return EXIT_FAILURE;
    previous->next = current->next;
    nodeCount--;
    free(current);
    return EXIT_SUCCESS;
}

int readFromTop(){
    node* current = head;
    int value;
    while (current != NULL) {
        value = current->data;
        current = current->next;
    }
    return value;
}

int readFromBeginning(){
    return (head)->data;
}


int searchList(int key) {
    node* current = head;
    while (current->next) {
        if (current->data == key) return EXIT_SUCCESS;
        current = current->next;
    }
    return EXIT_FAILURE;
}

void printList(void) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int getNodesCount() { return nodeCount; }

void freeList(void) {
    while (nodeCount) deleteFront();
    head = NULL;
}