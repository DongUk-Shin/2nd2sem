#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 20000
int sorted[MAX_SIZE];


//===================합병======================
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) 
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 	
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // 리스트의 균등분할
		merge_sort(list, left, mid);     // 부분리스트 정렬
		merge_sort(list, mid + 1, right);//부분리스트 정렬
		merge(list, left, mid, right);    // 합병
	}

}

//===================퀵======================
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
			SWAP(list[low], list[high], temp);

		}
	} while (low < high);
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
//===================기수======================
#define MAX_QUEUE_SIZE 15000
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
	return q->data[++(q->front)];
}

#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);	// 큐들의 초기화

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)				// 데이터들을 자리수에 따라 큐에 입력
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (b = i = 0; b < BUCKETS; b++)			// 버켓에서 꺼내어 list로 합친다.
			while (!is_empty(queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;				// 그 다음 자리수로 간다.
	}
}

int main()
{
	int merge_list[MAX_SIZE];
	int quick_list[MAX_SIZE];
	int radix_list[MAX_SIZE];

	int n = MAX_SIZE;
	int randomitem;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {      	// 난수 생성
		randomitem = rand() % 10000000 + 1;
		merge_list[i] = randomitem;
		quick_list[i] = randomitem;
		radix_list[i] = randomitem;
	}

	clock_t start1 = clock(); double result1;
	merge_sort(merge_list, 0, n - 1);	//합병정렬
	clock_t end1 = clock(); result1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\n합병 정렬 시간 %lf \n", result1);


	clock_t start2 = clock(); double result2;
	quick_sort(quick_list, 0, n - 1); // 퀵정렬
	clock_t end2 = clock(); result2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\n퀵 정렬 시간 %lf \n", result2);

	clock_t start3 = clock(); double result3;
	radix_sort(radix_list, MAX_SIZE); // 기수정렬
	clock_t end3 = clock(); result3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
	printf("\n기수 정렬 시간 %lf \n", result3);

	

}
