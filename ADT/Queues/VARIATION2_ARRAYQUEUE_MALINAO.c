#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10   

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue Q;

Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);  
void display(Queue* q);

int main() {
    Queue* q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Original Queue:\n");
    display(q);

    printf("\nAfter enqueue(Q, 50):\n");
    enqueue(q, 50);
    display(q);

    printf("\nAfter dequeue:\n");
    dequeue(q);
    display(q);

    return 0;
}

Queue* initialize() {
    Q.front = 1;
    Q.rear = 0;
    return &Q;
}

bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

int frontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("  items: [ ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d", q->items[i]);
        if ((i + 1) % MAX != (q->rear + 1) % MAX) printf(", ");
        i = (i + 1) % MAX;
    }
    printf(" ]\n");
    printf("  front: %d\n", q->front);
    printf("  rear: %d\n", q->rear);
}

