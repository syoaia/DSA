#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct stack {
	int items[MAX];
	int top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty (Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack *s);
void display(Stack* s);

int main(){
	Stack* S = initialize();
	
	push(S, 9);
	push(S, 7);
	push(S, 5);
	push(S, 3);
	push(S, 1);
	
	printf("Original List:\n");
	display(S);
	
	printf("\nAfter push(S, 8);\n");
	push(S, 8);
	display(S);
	
	printf("\nAfter pop(S);\n");
	int value = pop(S);
	display(S);
	printf("Value popped: %d\n", value);
	
	printf("\nPeek top element: %d\n", peek(S));
	printf("\nTop element: %d\n", top(S));

	free(S);
	return 0;
}

Stack* initialize(){
	Stack* s = (Stack*) malloc(sizeof(Stack));
	s->top= MAX;
	return s;
}

bool isFull(Stack* s){
	return s->top == 0;
}

bool isEmpty(Stack* s){
	return s->top == MAX;
}

void push(Stack* s, int value){
	if (isFull(s)){
		printf("Stack overflow! Cannot push %d\n", value);
		return;
	}
	s->items[--(s->top)] = value;
}

int pop(Stack* s){
	if (isEmpty(s)){
		printf("Stack underflow! Cannot pop.\n");
		return -1;
	}
	return s->items[(s->top)++];
}

int peek(Stack* s){
	if (isEmpty(s)){
		printf("Stack is empty. Nothing to peek.");
		return -1;
	}
	return s->items[s->top];
}

int top(Stack *s){
	return s->top;
}

void display(Stack* s){
	printf("items: [");
	int i;
	for(i = s->top; i < MAX; i++){
		printf("%d", s->items[i]);
		if (i < MAX -1) printf(", ");
	}
	printf("]\n");
	printf("top: %d\n", s->top);
}
