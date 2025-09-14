#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
	char elem[MAX];
	int count;
}charList;

bool findElem(charList L, char X);

int main(){
	charList L;
	L.count = 3;
	L.elem[0] = 'U';
	L.elem[1] = 'S';
	L.elem[2] = 'C';
	
	char X;
	bool result;
	
	charList emptyList;
	emptyList.count = 0;
	
	printf("\n***TEST CASES***\n\n");
	
	X = 'U';
	result = findElem(emptyList, X);
	printf("Case A: \nSearching for %c in empty list -> %s\n\n", X, result? "Found" : "Not Found");
	
	X = 'Z';
	result = findElem(L, X);
	printf("Case B: \nSearching for %c in {U,S,C} -> %s\n\n", X, result? "Found" : "Not Found");
	
	X = 'C';
	result = findElem(L, X);
	printf("Case C: \nSearching for %c in {U,S,C} -> %s\n\n", X, result? "Found" : "Not Found");

	return 0;
}

bool findElem(charList L, char X){
	bool found = false;
	int i;
	
	for(i = 0; i < L.count; i++){
		if(L.elem[i] == X){
			found = true;
		}
	}
	
	return found;
}

