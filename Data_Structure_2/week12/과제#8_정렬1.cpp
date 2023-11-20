#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
int STEP = 1;

void print_list(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");
}

void print_one_line(int list[], int n) {
	printf("STEP %d: \t", STEP++);
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


// 삽입정렬
void insertion_sort(int list[], int n)
{
	int i, j, key;
	STEP = 1;
	print_one_line(list, n);
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
		list[j + 1] = key;
		print_one_line(list, n);
	}
}

//선택
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	STEP = 1;
	print_one_line(list, n);
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 			// 최솟값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
		print_one_line(list, n);
	}
}

//버블
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	STEP = 1;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {	// 앞뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
			print_one_line(list, n);
		}
		
	}
	
}

//셸
void inc_insertion_sort(int list[], int first, int last, int gap)
{
	
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
		print_one_line(list, 10);
	}
}
//셸
void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	STEP = 1;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) 
			gap++;
		for (i = 0; i < gap; i++) {		// 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
		}
	}
}



int main() {

	int list[10], insertion[10], selection[10], bubble[10], sell[10];

	int random;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		random = rand() % 100 + 1;
		list[i] = random;
		insertion[i] = random; // 삽입
		selection[i] = random; //선택
		bubble[i] = random;	//버블
		sell[i] = random;	//셸
	}

	printf("원래 배열: ");
	print_list(list, 10);

	printf("-----------------------------------------------\n");

	printf("삽입정렬: \n");
	insertion_sort(insertion, 10);

	printf("-----------------------------------------------\n");

	printf("선택정렬: \n");
	selection_sort(selection, 10);

	printf("-----------------------------------------------\n");

	printf("버블정렬: \n");
	bubble_sort(bubble, 10);

	printf("-----------------------------------------------\n");

	printf("셸정렬: \n");
	shell_sort(sell, 10);


}