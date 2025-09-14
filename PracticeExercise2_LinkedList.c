#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	char elem;
	struct node *link;
}*charList;

bool findElem(charList L, char X);

int main(){
	charList L = NULL;
	charList temp, tail;
	char elements[3] ={'U','S','C'};
	
	int i;
	
	for(i = 0; i < 3; i++){
		temp = (charList)malloc(sizeof(struct node));
		temp->elem = elements[i];
		temp->link = NULL;
		
		if(L == NULL){
			L = temp;
			tail = temp;
		}else{
			tail->link = temp;
			tail = temp;
		}
	}
	
	printf("\n***TEST CASES***\n");
	
	char X;
	bool result;
	charList emptyList = NULL;
	
	X = 'U';
    result = findElem(emptyList, X);
    printf("Case A:\nSearching for %c in empty list -> %s\n\n", 
            X, result ? "Found" : "Not Found");

    X = 'Z';
    result = findElem(L, X);
    printf("Case B:\nSearching for %c in {U,S,C} -> %s\n\n", 
            X, result ? "Found" : "Not Found");
            
    X = 'C';
    result = findElem(L, X);
    printf("Case C:\nSearching for %c in {U,S,C} -> %s\n\n", 
            X, result ? "Found" : "Not Found");
            
    for(temp = L; temp != NULL;){
    	charList next = temp->link;
    	free(temp);
    	temp = next;
	}
	return 0;
}

bool findElem(charList L, char X){
	bool found = false;
	charList trav = L;
	
	for(; trav != NULL && !found; trav = trav->link){
		if(trav->elem == X){
			found = true;
		}
	}
	return found;
}
