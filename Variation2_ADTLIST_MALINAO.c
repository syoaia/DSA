#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
	int elem [MAX];
	int count;
}EType, *EPtr;

EPtr L;
void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
	int data; int position;
	EPtr L = (EPtr)malloc(sizeof(EType));
	
	initialize(L);
	insertPos(L, 3, 0);
    insertPos(L, 6, 1);
    insertPos(L, 12, 2);
    insertPos(L, 15, 3);
    insertPos(L, 21, 4);
    
    printf("Original List:\n");
    display(L);
    
    data = 18; position = 4;
    printf("\nL = insertPos(L, %d, %d)\n", data, position);
    insertPos(L, data, position);
    printf("After insertPos:\n");
    display(L);
    
    position = 0;
    printf("\nL = deletePos(L, %d)\n", position);
    deletePos(L, position);
    printf("After deletePos:\n");
    display(L);
    
    data = 15; 
    position = locate(L, data);
    if (position != -1){
    	printf("\n%d found at index %d.\n", data, position);
	}
    
    position = 3;
    printf("\nRetrieved element at index %d: %d\n", position, retrieve(L, position));
    
	data = 3;
    printf("\nL = insertSorted(L, %d)\n", data);
    insertSorted(L, data);
    printf("After insertSorted:\n");
    display(L);

    makeNULL(L);
    return 0;
}

void initialize(EPtr L){
	L->count = 0;
}

void insertPos(EPtr L, int data, int position){
	int i;
	if(position <= L->count && L->count < MAX){
		for(i = L->count; i > position; i--){
			L->elem[i] = L->elem[i-1];
		}
		L->elem[position] = data;
		L->count++;
	}
}

void deletePos(EPtr L, int position){
	int i;
	if(position < L->count){
		for(i = position; i < L->count -1; i++ ){
			L->elem[i] = L->elem[i+1];
		}
		L->count--;
	}
}

int locate(EPtr L, int data){
	int i;
	for(i = 0; i < L->count; i++){
		if(L->elem[i] == data) return i;
	}
	return -1;
}

int retrieve(EPtr L, int position){
	int i;
	if(position < L->count){
		return L->elem[position];
	}
	return -1;
}

void insertSorted(EPtr L, int data){
	int i;
	if(L->count < MAX){
		int pos = 0;
		for(; pos < L->count; pos++){
			if(L->elem[pos] >= data) break;
		}
		for(i = L->count; i > pos; i--){
			L->elem[i] = L->elem[i-1];
		}
		L->elem[pos] =  data;
		L->count++;
	}
}

void display(EPtr L){
	int i;
	printf("	elem:[");
    for(i = 0; i < L->count; i++){
        printf(" %d", L->elem[i]);
    }
    printf(" ]\n");
    printf("	count: %d\n", L->count);
}

void makeNULL(EPtr L){
	free(L);
}
