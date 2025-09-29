#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Stack{
	Node* top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

Stack* initialize(){
	Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation for stack failed!\n");
        exit(1);
    }
    s->top = NULL;
    return s;
}

bool isFull(Stack* s){
	return false;
}

bool isEmpty(Stack* s){
	return(s->top == NULL);
}

void push(Stack* s, int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Memory allocation failed! Push aborted.\n");
		return;
	}
	newNode->data = value;
	newNode->next = s->top;
	s->top = newNode;
}

int pop(Stack* s){
	if(isEmpty(s)){
		printf("Stack underflow! Nothing to pop.\n");
		return -1;
	}
	Node* temp = s->top;
	int value = temp->data;
	s->top = s->top->next;
	free(temp);
	return value;
}

int peek(Stack* s){
	if(isEmpty(s)){
		printf("Stack is empty. Nothing to peek.\n");
		return -1;
	}
	return s->top->data;
}

void display(Stack* s){
	if (isEmpty(s)) {
       printf("Stack is empty.\n");
       return;
    }
    printf("Stack (top -> bottom): ");
    Node* current;
    for (current = s->top; current != NULL; current = current->next) {
    	printf("%d ", current->data);
    }
    printf("\n");
}

int main(){
	Stack* S = initialize();
	
	push(S, 1);
	push(S, 3);
	push(S, 6);
	push(S, 2);
	push(S, 4);
	push(S, 5);
	
	printf("Original List:\n");
	display(S);
	
	printf("\nAfter push(S, 7); \n");
	push(S, 7);
	display(S);
	
	printf("\nPopped: %d\n", pop(S));
	display(S);
	
	printf("\nPeek: %d\n", peek(S));
	
	return 0;	
}
