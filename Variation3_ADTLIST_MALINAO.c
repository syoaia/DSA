#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List  insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){
	int data; int position;
	
	List L = initialize(L);
	L = insertPos(L, 3, 0);
    L = insertPos(L, 6, 1);
    L =insertPos(L, 12, 2);
    L = insertPos(L, 15, 3);
    L = insertPos(L, 21, 4);
    
    printf("Original List:\n");
    display(L);
    
    data = 10; position = 0;
    printf("\nL = insertPos(L, %d, %d)\n", data, position);
    L = insertPos(L, data, position);
    printf("After insertPos:\n");
    display(L);
    
    position = 0;
    printf("\nL = deletePos(L, %d)\n", position);
    L = deletePos(L, position);
    printf("After deletePos:\n");
    display(L);
    
    data = 9; 
    position = locate(L, data);
    if (position != -1){
    	printf("\n%d found at index %d.\n", data, position);
	}
    
	data = 2;
    printf("\nL = insertSorted(L, %d)\n", data);
    L = insertSorted(L, data);
    printf("After insertSorted:\n");
    display(L);
	
	free(L.elemPtr);
	return 0;
}

List initialize(List L){
	L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
	L.count = 0;
	L.max = LENGTH;
	return L;
}

List insertPos(List L, int data, int position){
	int i;
	if (position <= L.count){
		if(L.count == L.max){
			L = resize(L);
		}
		for(i =L.count; i>position; i--){
			L.elemPtr[i] = L.elemPtr[i-1];
		}
		L.elemPtr[position] = data;
		L.count++;
	}
	return L;
}

List deletePos(List L, int position){
	int i; 
	if(position < L.count){
		for(i = position; i < L.count - 1; i++){
			L.elemPtr[i] = L.elemPtr[i+1];
		}
		L.count--;
	}
	return L;
}

int locate(List L, int data){
	int i;
	for(i = 0; i < L.count; i++){
		if(L.elemPtr[i] == data) return i;
	}
	return -1;
}

List  insertSorted(List L, int data){
	int i; 
	if(L.count == L.max){
		L = resize(L);
	}
	int pos;
	for(pos = 0;pos < L.count; pos++){
		if(L.elemPtr[pos] >= data) break;
	}
	for(i = L.count; i > pos; i--){
		L.elemPtr[i] = L.elemPtr[i - 1];
	}
	L.elemPtr[pos] = data;
	L.count++;
	return L;
}

void display(List L){
	int i;
	printf("	elem:[");
    for(i = 0; i < L.count; i++){
        printf(" %d", L.elemPtr[i]);
    }
    printf(" ]\n");
    printf("	count: %d\n", L.count);
}

List resize(List L){
	L.max *= 2;
	L.elemPtr = (int*)realloc(L.elemPtr, L.max * sizeof(int));
	return L; 	
}






