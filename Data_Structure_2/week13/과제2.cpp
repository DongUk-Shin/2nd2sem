#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 10
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void print_list_merge(int list[]) {
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // ����Ʈ�� �յ����
		merge_sort(list, left, mid);     // �κи���Ʈ ����
		merge_sort(list, mid + 1, right);//�κи���Ʈ ����
		merge(list, left, mid, right);    // �պ�
		print_list_merge(list);
	}

}



void print_list_quick(int list[], int low, int high) {
	for (int i = 0; i < MAX_SIZE; i++)
		printf(" %d ", list[i]);
	printf("\n");
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i] == list[low])
			printf("low ");
		else if (list[i] == list[high])
			printf("high");
		else
			printf("    ");
	}
	printf("\n");
}


int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) {
			print_list_quick(list, low, high);
			SWAP(list[low], list[high], temp);

		}
	} while (low < high);
	print_list_quick(list, low, high);
	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}


#define MAX_QUEUE_SIZE 100
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

void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("#|");
		else
			printf("%d|", q->data[i]);
	}
	printf("\n");
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
	return q->data[++(q->front)];
}



#define BUCKETS 10
#define DIGITS 3

void print_radix_list(int list[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}


void radix_sort(int list[], int n)
{
	printf("�ʱⰪ:\n");
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	for (b = 0; b < BUCKETS; b++) 
		init_queue(&queues[b]);	// ť���� �ʱ�ȭ

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)				// �����͵��� �ڸ����� ���� ť�� �Է�
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		print_radix_list(list, n);
		
		for (b = i = 0; b < BUCKETS; b++)			// ���Ͽ��� ������ list�� ��ģ��.
			while (!is_empty(queues[b]))
				list[i++] = dequeue(&queues[b]);
		
		factor *= 10;				// �� ���� �ڸ����� ����.
	}
}

int main(void)
{
	int merge_list[MAX_SIZE];
	int quick_list[MAX_SIZE];
	int radix_list[MAX_SIZE];

	int n = MAX_SIZE;
	int randomitem;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {      	// ���� ����
		randomitem = rand() % 100 + 1;
		merge_list[i] = randomitem;
		quick_list[i] = randomitem;
		radix_list[i] = randomitem;
	}

	printf("�ʱⰪ: ");
	for (int i = 0; i < MAX_SIZE; i++) {      	// ���� ����
		printf("%d ", merge_list[i]);
	}
	printf("\n");

	merge_sort(merge_list, 0, n - 1);
	printf("==========================================\n");
	printf("�ʱⰪ: \n");
	quick_sort(quick_list, 0, n - 1); // ������ ȣ�� 
	printf("==========================================\n");
	radix_sort(radix_list, MAX_SIZE);
	return 0;
}





