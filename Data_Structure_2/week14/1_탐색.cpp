#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200000

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

void print_list(int list[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d ", list[i]);
	}
}

int compare_count_seq = 0;
int seq_search(int key, int low, int high, int list[])
{
	int i;
	for (i = low; i <= high; i++) {
		compare_count_seq++;
		if (list[i] == key)
			return i; // 탐색 성공
	}
	return -1;    	// 탐색 실패
}

int compare_count_binary = 0;
int search_binary2(int key, int low, int high, int list[])
{
	int middle;
	while (low <= high) { 				// 아직 숫자들이 남아 있으면
		middle = (low + high) / 2;
		compare_count_binary++;
		if (key == list[middle])
			return middle; 	// 탐색 성공
		else if (key > list[middle])
			low = middle + 1; 	// 왼쪽 부분리스트 탐색
		else
			high = middle - 1; 			// 오른쪽 부분리스트 탐색
	}
	return -1; 					// 탐색 실패
}

int main() {
	srand(time(NULL));
	int list[MAX];

	for (int i = 0; i < MAX; i++) {
		list[i] = rand() % MAX + 1;
	}
	int key = rand() % MAX + 1;

	clock_t start1 = clock(); double result1;
	printf("\nkey:%d\t비교횟수:%d\t리스트의 인덱스:%d", key, compare_count_seq, seq_search(key, 0, MAX, list));
	clock_t end1 = clock(); result1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\n순차 탐색 시간 %lf \n", result1);

	qsort(list, sizeof(list) / sizeof(int), sizeof(int), compare);

	clock_t start2 = clock(); double result2;
	printf("\nkey:%d\t비교횟수:%d\t리스트의 인덱스:%d", key, compare_count_binary, search_binary2(key, 0, MAX, list));
	clock_t end2 = clock(); result2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\n이진 탐색 시간 %lf \n", result2);

}

