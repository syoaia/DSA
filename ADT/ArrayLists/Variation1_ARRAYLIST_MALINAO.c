#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
	int elem [MAX];
	int count;
}List;

List L;
List initialize (List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
	int data; int position;
	
    List L = initialize(L);
    L = insertPos(L, 3, 0);
    L = insertPos(L, 6, 1);
    L = insertPos(L, 12, 2);
    L = insertPos(L, 15, 3);
    
    printf("Original List:\n");
    display(L);
    
    data = 9; position = 2;
    printf("\nL = insertPos(L, %d, %d)\n", data, position);
    L = insertPos(L, data, position);
    printf("After insertPos:\n");
    display(L);
    
    position = 4;
    printf("\nL = deletePos(L, %d)\n", position);
    L= deletePos(L, position);
    printf("After deletePos:\n");
    display(L);
    
    data = 3;
    position = locate(L, data);
    if(position != -1){
        printf("\n%d found at index %d.\n", data, position);
    }

    data = 11;
    printf("\nL = insertSorted(L, %d)\n", data);
    L = insertSorted(L, data);
    printf("After insertSorted:\n");
    display(L);

    return 0;
}

List initialize (List L){
	L.count = 0;
	return L;
}

List insertPos(List L, int data, int position){
	int i;
	if(position <= L.count && L.count < MAX){
        for(i = L.count; i > position; i--){
            L.elem[i] = L.elem[i-1];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}
   

List deletePos(List L, int position){
	int i;
    if(position < L.count){
        for(i = position; i < L.count - 1; i++){
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data){
	int i;
    for(i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
	int i; int pos;
    if(L.count < MAX){
        int pos;
        for(pos = 0; pos < L.count; pos++){
            if(L.elem[pos] >=data) break;
        }
        for(i = L.count; i > pos; i--){
        L.elem[i] = L.elem[i - 1];
        }
        L.elem[pos] = data;
        L.count++;
    }
    return L;
}

void display (List L){
	int i;
    printf("	elem:[");
    for(i = 0; i < L.count; i++){
        printf(" %d", L.elem[i]);
    }
    printf(" ]\n");
    printf("	count: %d\n", L.count);
}
