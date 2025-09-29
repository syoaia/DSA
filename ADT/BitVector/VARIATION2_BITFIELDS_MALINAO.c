#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned char field : 8;
} Set;

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    if (element < 0 || element >= 8) return;
    set->field |= (1 << element);
}

void delete(Set *set, int element) {
    if (element < 0 || element >= 8) return;
    set->field &= ~(1 << element);
}

bool find(Set set, int element) {
    if (element < 0 || element >= 8) return false;
    return (set.field & (1 << element)) != 0;
}

Set set_union(Set A, Set B) {
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B) {
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) {
    Set C;
    C.field = A.field & ~B.field;
    return C;
}

void display(Set set) {
    printf("{ ");
    int i;
    for (i = 0; i < 8; i++) {
        if (set.field & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);
    printf("A = "); display(A);

    insert(&B, 2);
    insert(&B, 5);
    printf("B = "); display(B);

    C = set_union(A, B);
    printf("A ? B = "); display(C);

    C = intersection(A, B);
    printf("A n B = "); display(C);

    C = difference(A, B);
    printf("A - B = "); display(C);

    delete(&A, 5);
    printf("After deleting 5 from A: "); display(A);

    printf("Find 0 in A: %s\n", find(A, 0) ? "Yes" : "No");
    printf("Find 5 in A: %s\n", find(A, 5) ? "Yes" : "No");

    return 0;
}

