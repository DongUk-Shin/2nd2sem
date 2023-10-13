#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    int key;
} element;

typedef struct{
    element heap[MAX];
    int size;
} HeapType;

HeapType* create() {
    return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h) {
    h->size = 0;
}

void imh(HeapType *h, element item) {
    int i = ++(h->size);
    while((i != 1) && (item.key > h->heap[i/2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element dmh(HeapType *h) {
    element item = h->heap[1];
    element temp = h->heap[(h->size)--];
    int p = 1, c = 2;

    while (c <= h->size) {
        if ((c < h->size) && (h->heap[c].key < h->heap[c + 1].key))
            c++;
        if (temp.key > h->heap[c].key)
            break;
        h->heap[p] = h->heap[c];
        p = c;
        c *= 2;
    }
    h->heap[p] = temp;
    return item;
}
void print_heap(HeapType *h) {
	printf("\nheap status: ");
	for (int i = 1; i <= h->size; i++) {
		printf("%d ", h->heap[i]);
	}
	
}
int main() {
    HeapType *h;
    h = create();
    init(h);

    element e1 = {10};
    imh(h, e1);

    element e2 = {1};
    imh(h, e2);
    element e3 = {3};
    imh(h, e3);
    element e4 = {4};
    imh(h, e4);
    element e5 = {99};
    imh(h, e5);
    element e6 = {223};
    imh(h, e6);

    print_heap(h);

    printf("\nd: %d", dmh(h));
    print_heap(h);
}