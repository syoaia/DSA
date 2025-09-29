#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

typedef struct {
	int elem;
	int next;
}Cell, HeapSpace[MAX];

typedef struct {
	HeapSpace H;
	int avail;
}VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap*V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void deleteElem(int* L, VHeap* V, int elem);
void deleteAllOccurence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main(){
	VHeap VH;
    List L = -1; // empty list

    initialize(&VH);

    insertFirst(&L, &VH, 10);
    insertFirst(&L, &VH, 20);
    insertLast(&L, &VH, 30);
    insertSorted(&L, &VH, 15);

    display(L, VH);

    deleteElem(&L, &VH, 20);
    display(L, VH);

    insertFirst(&L, &VH, 10);
    insertLast(&L, &VH, 10);
    display(L, VH);

    deleteAllOccurrence(&L, &VH, 10);
    display(L, VH);

    return 0;
}

void initialize(VHeap *V){
	int i;
	for(i = 0; i < MAX - 1; i++){
		V->H[i].next = i+1;
	}
	V->H[i].next = -1;
	V->avail  = 0;
}

int allocSpace(VHeap* V){
	int index = -1;
	if(V->avail != -1){
		index = V->avail;
		V->avail = V->H[index].next;
	}
	return index;
}

void deallocSpce(VHeap* V, int index){
	if(index >= 0 && index < MAX){
		V->H[index].next = V->avail;
		V->avail = index;
	}
}

void insertFirst(int* L, VHeap* V, int elem){
	int newIndex = allocSpace(V);
	if(newIndex != 1){
		V->H[newIndex].elem = elem;
		V->H[newIndex].next = *L;
		*L = newIndex;
	}else{
		printf("No space available!\n");
	}
}

void insertLast(int* L, VHeap* V, int elem){
	int newIndex = allocSpace(V);
	if(newIndex != -1){
		V->H[newIndex].elem = elem;
		V->H[newIndex].next = -1;
		if(*L == -1){
			*L = newIndex;
		}else{
			int temp = *L;
			for(temp = *L; V->H[temp].next != -1; temp = V->H[temp].next){
			}
			V->H[temp].next = newIndex;
		}
	}else{
		printf("No space available!\n");
	}
	
}

void insertSorted(int* L, VHeap* V, int elem){
	int newIndex = allocSpace(V);
	if(newIndex !=-1){
		V->H[newIndex].elem = elem;
		
		if(*L == -1 || elem < V->H[*L].elem){
			V->H[newIndex].next = *L;
			*L = newIndex;
		}else{
			int prev = *L;
			int curr = V->H[*L].next;
			
			for(; curr != -1 && V->H[curr].elem < elem; prev = curr,
			curr = V->H[curr].next){
			}
			V->H[newIndex].next = curr;
            V->H[prev].next = newIndex;
		}
	}else{
		printf("No space available!\n");
	}
}

void deleteElem(int* L, VHeap* V, int elem){
	int prev = -1, curr;

    for (curr = *L; curr != -1 && V->H[curr].elem != elem; prev = curr,
	 curr = V->H[curr].next) {   
    }
    if (curr != -1) {
        if (prev == -1) { 
            *L = V->H[curr].next;
        } else {
            V->H[prev].next = V->H[curr].next;
        }
        deallocSpace(V, curr);
    }
}

void deleteAllOccurence(int* L, VHeap* V, int elem){
	int prev = -1, curr, next;

    for (curr = *L; curr != -1; curr = next) {
        next = V->H[curr].next;
        
      	if (V->H[curr].elem == elem) {
            if (prev == -1) { 
                *L = next;
            } else {
                V->H[prev].next = next;
            }
            deallocSpace(V, curr);
        } else {
            prev = curr;
        }
    }  
}

void display(int L, VHeap V){
	printf("List: ");
	int i;
    for (i = L; i != -1; i = V.H[i].next) {
        printf("%d ", V.H[i].elem);
    }
    printf("\n");
}


