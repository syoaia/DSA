#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef struct {
    bool elements[ARRAY_SIZE];
} Set;

void initialize(Set *set) {
	int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        set->elements[i] = false;
}

void insert(Set *set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return;
    set->elements[element] = true;
}

void delete(Set *set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return;
    set->elements[element] = false;
}

bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return false;
    return set.elements[element];
}

void set_union(Set A, Set B, Set *C) {
	int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        C->elements[i] = A.elements[i] || B.elements[i];
}

void intersection(Set A, Set B, Set *C) {
	int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        C->elements[i] = A.elements[i] && B.elements[i];
}

void difference(Set A, Set B, Set *C) {
	int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        C->elements[i] = A.elements[i] && !B.elements[i];
}

void display(Set set) {
    printf("{ ");
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (set.elements[i]) printf("%d ", i);
    }
    printf("}\n");
}

int main() {
    Set A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 0);
    insert(&A, 2);
    insert(&A, 7);
    printf("A = "); display(A);

    insert(&B, 2);
    insert(&B, 4);
    insert(&B, 5);
    printf("B = "); display(B);

    set_union(A, B, &C);
    printf("A ? B = "); display(C);

    intersection(A, B, &C);
    printf("A n B = "); display(C);

    difference(A, B, &C);
    printf("A - B = "); display(C);

    delete(&A, 0);
    delete(&A, 7);
    printf("After deleting 0 and 7 from A: "); display(A);

    printf("Find 2 in A: %s\n", find(A, 2) ? "Yes" : "No");
    printf("Find 7 in A: %s\n", find(A, 7) ? "Yes" : "No");

    return 0;
}

