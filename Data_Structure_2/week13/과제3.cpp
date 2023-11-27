#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}


int is_full(QueueType q) {
	return (q.rear == MAX_QUEUE_SIZE - 1);
}

int is_empty(QueueType q) {
	return (q.rear == q.front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(*q)) {
		printf("Queue is full.\n");
		return;
	}
	q->data[++(q->rear)] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(*q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	element item = q->data[++(q->front)];
	return item;
}

#define BUCKETS 10
#define DIGITS 3

void print_bucket(QueueType* queues) { 
	for (int i = 0; i < BUCKETS; i++) { //��� ť�� ���� ���
		printf("[%d]-> \t", i);
		for (int j = queues[i].front + 1; j <= queues[i].rear; j++) {
			printf("%d  ", queues[i].data[j]);
		}
		printf("\n");
	}
	printf("\n");
}

void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	for (b = 0; b < BUCKETS; b++)
		init_queue(&queues[b]);	// ť���� �ʱ�ȭ

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)				// �����͵��� �ڸ����� ���� ť�� �Է�
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		
		print_bucket(queues); 
		for (b = i = 0; b < BUCKETS; b++)			// ���Ͽ��� ������ list�� ��ģ��.
			while (!is_empty(queues[b]))
				list[i++] = dequeue(&queues[b]);

		factor *= 10;				// �� ���� �ڸ����� ����.
	}
}

int main(void)
{
	int radix_list[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {      	// ���� ����
		radix_list[i] = rand() % 500 + 1;
	}

	radix_sort(radix_list, MAX_SIZE);

	return 0;
}