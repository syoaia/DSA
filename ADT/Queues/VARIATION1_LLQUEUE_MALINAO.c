#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

Queue* initialize() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation for queue failed!\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q) {
    return false;
}

bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Enqueue aborted.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow! Nothing to dequeue.\n");
        return -1; 
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing at front.\n");
        return -1;
    }
    return q->front->data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front -> rear): ");
    Node* current;
    for (current = q->front; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");
}

int main() {
    Queue* Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    enqueue(Q, 7);
    enqueue(Q, 9);
    enqueue(Q, 11);
    
    printf("Original List:\n");
    display(Q);

    printf("\nAfter enqueue(Q, 13):\n");
    enqueue(Q, 13);
    display(Q);

    printf("\nDequeued: %d\n", dequeue(Q));
    display(Q);

    printf("\nFront: %d\n", front(Q));

    return 0;
}

