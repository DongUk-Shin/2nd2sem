/*
연습문제6번 3
히프정렬
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;


HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1;
	child = 2;
	while (child <= h->heap_size) {

		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key < h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;

	}
	h->heap[parent] = temp;
	return item;
}

void print_heap(HeapType *h) {
	printf("\nheap status: ");
	for (int i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i]);
	}
	
}

int main() {

	HeapType* heap;

	heap = create();
	init(heap);

	int a[] = { 71, 49, 92, 55, 38, 82, 72, 53 };

	element e;

	for (int i = 0; i < 8; i++) {
		e.key = a[i];
		insert_min_heap(heap, e);
		print_heap(heap);
	}
	printf("\n");	
	element d;

	for (int i = 0; i < 8; i++) {
		print_heap(heap);
		d = delete_min_heap(heap);
		printf("\ndelete: %d ", d.key);
		
	}
	printf("\n");
}
