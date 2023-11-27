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
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
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
		mid = (left + right) / 2;              // 리스트의 균등분할
		merge_sort(list, left, mid);     // 부분리스트 정렬
		merge_sort(list, mid + 1, right);//부분리스트 정렬
		merge(list, left, mid, right);    // 합병
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
	printf("초기값:\n");
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	for (b = 0; b < BUCKETS; b++) 
		init_queue(&queues[b]);	// 큐들의 초기화

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)				// 데이터들을 자리수에 따라 큐에 입력
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		print_radix_list(list, n);
		
		for (b = i = 0; b < BUCKETS; b++)			// 버켓에서 꺼내어 list로 합친다.
			while (!is_empty(queues[b]))
				list[i++] = dequeue(&queues[b]);
		
		factor *= 10;				// 그 다음 자리수로 간다.
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
	for (int i = 0; i < MAX_SIZE; i++) {      	// 난수 생성
		randomitem = rand() % 100 + 1;
		merge_list[i] = randomitem;
		quick_list[i] = randomitem;
		radix_list[i] = randomitem;
	}

	printf("초기값: ");
	for (int i = 0; i < MAX_SIZE; i++) {      	// 난수 생성
		printf("%d ", merge_list[i]);
	}
	printf("\n");

	merge_sort(merge_list, 0, n - 1);
	printf("==========================================\n");
	printf("초기값: \n");
	quick_sort(quick_list, 0, n - 1); // 퀵정렬 호출 
	printf("==========================================\n");
	radix_sort(radix_list, MAX_SIZE);
	return 0;
}





