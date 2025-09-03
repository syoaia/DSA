#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct{
	Node *head;
	int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
	List *L = initialize();
	
	insertPos(L, 2, 0);
    insertPos(L, 6, 1);
    insertPos(L, 5, 2);
    insertPos(L, 8, 3);
    
    printf("Original List:\n");
    display(L);
    
    printf("\ninsertFirst(L, 7);\n");
    insertFirst(L, 7);
    printf("After:\n");
    display(L);
    printf("\n");

    printf("\ninsertLast(L, 9);\n");
    insertLast(L, 9);
    printf("After:\n");
    display(L);
    printf("\n");

    printf("\ninsertPos(L, 1, 2);\n");
    insertPos(L, 1, 2);
    printf("After:\n");
    display(L);
    printf("\n");

    printf("\ndeleteStart(L);\n");
    deleteStart(L);
    printf("After:\n");
    display(L);
    printf("\n");

    printf("\ndeleteLast(L);\n");
    deleteLast(L);
    printf("After:\n");
    display(L);
    printf("\n");

    printf("\ndeletePos(L, 1);\n");
    deletePos(L, 1);
    printf("After:\n");
    display(L);
    printf("\n");

    printf("value at index 2 is: %d\n", retrieve(L, 2));
    int pos = locate(L, 5);
    if (pos == -1) {
        printf("That number is not in the list\n");
    } else {
        printf("Your number is found at index %d\n", pos);
    }
    printf("\n");

    printf("Before emptying:\n");
    display(L);
    printf("\nempty(L);\n\n");
    empty(L);
    printf("After emptying:\n");
    display(L);

    free(L);
    return 0;
}

List* initialize(){
	List *list = (List*)malloc(sizeof(List*));
	list->head = NULL;
	list->count = 0;
	return list;
}

void empty(List *list){
	Node *current;
	for(current = list->head; current != NULL;){
		Node *temp =  current;
		current = current->next;
		free(temp);
	}
	list->head = NULL;
	list->count = 0;
}

void insertFirst(List *list, int data){
	Node *newNode = (Node*)malloc(sizeof(Node*));
	newNode->data = data;
	newNode->next = list->head;
	list->head = newNode;
	list->count++;
}

void insertLast(List *list, int data){
	Node *newNode = (Node*)malloc(sizeof(Node*));
	newNode->data = data;
	newNode->next = NULL;
	
	if(!list->head){
		list->head = newNode;
	}else{
		Node *current;
		for(current = list->head; current->next != NULL; current = current->next);
		current->next = newNode;
	}
	list->count++;
}

void insertPos(List *list, int data, int index){
	if(index < 0 || index > list->count) return;
	
	if(index == 0){
		insertFirst(list, data);
	}else{
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		
		Node *current;
		for(current = list->head; index > 1; index--, current = current->next);
		newNode->next = current->next;
		current->next = newNode;
		list->count++;
	}
}


void deleteStart(List *list){
	if(!list->head) return;
	
	Node *temp = list->head;
	list->head = list->head->next;
	free(temp);
	list->count--;
}

void deleteLast(List *list){
	if(!list->head) return;
	
	if(!list->head->next){
		free(list->head);
		list->head = NULL;
	}else{
		Node *current;
		for(current = list->head; current->next->next != NULL; current = current->next);
		free(current->next);
		current->next = NULL;
	}
	list->count--;
}

void deletePos(List *list, int index){
	if(index < 0 || index >= list->count) return;
	
	if(index == 0){
		deleteStart(list);
	}else{
		Node *current = list->head;
		int i;
		for(i = 0; i < index - 1; i++)
			current = current->next;
			
		Node *temp = current->next;
		current->next = temp->next;
		free(temp);
		list->count--;
	}
}

int retrieve(List *list, int index){
	if(index < 0 || index >= list->count) return -1;
	
	Node *current = list->head;
	int i;
	for(i = 0; i< index; i++)
		current = current->next;
	
	return current->data;
}

int locate(List *list, int data){
	Node *current;
	int index;
	for (current = list->head, index = 0; current !=NULL; current = current->next, index++)
		if(current->data ==data) return index;
		
	return -1;		
}

void display(List *list){
	printf("head:");
	Node *current;
	for(current = list->head; current != NULL; current = current->next)
		printf("%d -> ", current->data);
	printf("NULL\n");
	printf("count: %d\n", list->count);	
}
