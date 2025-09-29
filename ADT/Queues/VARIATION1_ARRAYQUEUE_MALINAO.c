#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int items[MAX];
	int count;
}List;

typedef struct{
	List list;
	int front;
	int rear;
}Queue;

Queue Q;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main(){
	Queue* q = initialize();
	
	enqueue(q, 10);
	enqueue(q, 30);
	enqueue(q, 40);
	enqueue(q, 60);
	enqueue(q, 20);
	enqueue(q, 50);
	
	printf("Original Queue:\n");
	display(q);
	
	printf("\nAfter enqueue(Q, 70):\n");
	enqueue(q, 70);
	display(q);
	
	printf("\nAfter dequeue:\n");
	dequeue(q);
	display(q);
	
	return 0;
}

Queue* initialize(){
	Q.list.count = 0;
	Q.front = 0;
	Q.rear = -1;
	return &Q;
}

bool isFull(Queue* q){
	return q->list.count == MAX;
}

bool isEmpty(Queue* q){
	return q->list.count == 0;
}

void enqueue(Queue* q, int value){
	if(isFull(q)){
		printf("Queue is full!\n");
		return;
	}
	if(isEmpty(q)){
		q->front = q->rear = 0;
	}else{
		q->rear = (q->rear + 1) % MAX;
	}
	q->list.items[q->rear] = value;
	q->list.count++;
}

int dequeue(Queue* q){
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return -1;
	}
	int value = q->list.items[q->front];
	if(q->list.count ==1){
		q->front = q->rear = -1;
	}else{
		q->front = (q->front + 1) % MAX;
	}
	q->list.count--;
	return value;
}

int front(Queue* q){
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return -1;
	}
	return q->list.items[q->front];
}

void display(Queue* q){
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return;
	}
	printf("  items: [ ");
    int i = q->front;
    int c;
    for (c = 0; c < q->list.count; c++) {
        printf("%d", q->list.items[i]);
        if (c < q->list.count - 1) printf(", ");
        i = (i + 1) % MAX;
    }
    printf(" ]\n");
    printf("  count: %d\n", q->list.count);
    printf("  front: %d\n", q->front);
    printf("  rear: %d\n", q->rear);
}
