/*
20204101 신동욱
과제#1-1 minheap
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

int main() {

	HeapType* heap;

	heap = create();
	init(heap);

	int a[] = { 10, 40, 30, 5, 12, 6, 15, 9, 60 };

	element e;

	for (int i = 0; i < 9; i++) {
		e.key = a[i];
		insert_min_heap(heap, e);
	}

	element d;

	for (int i = 0; i < 9; i++) {
		d = delete_min_heap(heap);
		printf("%d ", d.key);
	}
	printf("\n");
}
