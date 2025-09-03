#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){
	int data; int position;
	List L;
	
	initialize(&L);
	insertPos(&L, 3, 0);
    insertPos(&L, 6, 1);
    insertPos(&L, 9, 2);
    insertPos(&L, 12, 3);
    insertPos(&L, 18, 4);
    
    printf("Original List:\n");
    display(&L);

    data = 15; position = 4;
    printf("\nL = insertPos(L, %d, %d)\n", data, position);
    insertPos(&L, data, position);
    printf("After insertPos:\n");
    display(&L);

    position = 0;
    printf("\nL = deletePos(L, %d)\n", position);
    deletePos(&L, position);
    printf("After deletePos:\n");
    display(&L);

    data = 9;
    position = locate(&L, data);
    if(position != -1){
        printf("\n%d found at index %d.\n", data, position);
    }
    
    position = 3;
    printf("\nRetrieved element at index %d: %d\n", position, retrieve(&L, position));

    data = 2;
    printf("\nL = insertSorted(L, %d)\n", data);
    insertSorted(&L, data);
    printf("After insertSorted:\n");
    display(&L);

    makeNULL(&L);
    return 0;
}

void initialize(List *L){
	L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(List *L, int data, int position){
	int i;
    if(position <= L->count){
        if(L->count == L->max)resize(L);
        for(i = L->count; i > position; i--){
            L->elemPtr[i] = L->elemPtr[i-1];
        }
        L->elemPtr[position] = data;
        L->count++;
    }

}

void deletePos(List *L, int position){
	int i;
    if(position < L->count){
        for(i = position; i < L->count - 1; i++){
            L->elemPtr[i] = L->elemPtr[i+1];
        }
        L->count--;
    }
}

int locate(List *L, int data){
	int i;
    for(i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data) return i;
    }
    return -1;
}

int retrieve(List *L, int position){
	if(position >= 0 && position < L->count){
        return L->elemPtr[position];
    }
    return -1;
}

void insertSorted(List *L, int data){
	int i; 
    if(L->count == L->max)resize(L);
    int pos;
    for(pos = 0; pos < L->count; pos++){
        if(L->elemPtr[pos] >= data) break;
    }
    for(i = L->count; i > pos; i--){
        L->elemPtr[i] = L->elemPtr[i-1];
    }
    L->elemPtr[pos] = data;
    L->count++;
}

void display(List *L){
	int i;
	printf("	elem:[");
    for(i = 0; i < L->count; i++){
        printf(" %d", L->elemPtr[i]);
    }
    printf(" ]\n");
    printf("	count: %d\n", L->count);
}

void resize(List *L){
	L->max *= 2;
    L->elemPtr = (int*)realloc(L->elemPtr, L->max * sizeof(int));
}

void makeNULL(List *L){
	free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}
