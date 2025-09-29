#include <stdio.h>
#include <stdbool.h>

void initialize(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int element) {
    if (element < 0 || element >= 8) {
        printf("Element %d out of range (0–7).\n", element);
        return;
    }
    *set |= (1 << element);
}

void delete(unsigned char *set, int element) {
    if (element < 0 || element >= 8) {
        printf("Element %d out of range (0–7).\n", element);
        return;
    }
    *set &= ~(1 << element);
}

bool find(unsigned char set, int element) {
    if (element < 0 || element >= 8) return false;
    return (set & (1 << element)) != 0;
}

unsigned char set_union(unsigned char A, unsigned char B) {
    return (A | B);
}

unsigned char intersection(unsigned char A, unsigned char B) {
    return (A & B);
}

unsigned char difference(unsigned char A, unsigned char B) {
    return (A & ~B);
}

void display(unsigned char set) {
    printf("{ ");
    int i;
    for (i = 0; i < 8; i++) {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    unsigned char A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 1);
    insert(&A, 6);
    printf("A = "); display(A); // {1, 6}

    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);
    printf("B = "); display(B); // {3, 6, 7}

    C = set_union(A, B);
    printf("A ? B = "); display(C);

    C = intersection(A, B);
    printf("A n B = "); display(C);

    C = difference(A, B);
    printf("A - B = "); display(C);

    delete(&A, 6);
    printf("After deleting 6 from A: "); display(A);

    printf("Find 1 in A: %s\n", find(A, 1) ? "Yes" : "No");
    printf("Find 6 in A: %s\n", find(A, 6) ? "Yes" : "No");

    return 0;
}

