#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define SIZE 30000

// 삽입정렬
void insertion_sort(int list[], int n)
{
	int i, j, key;
	clock_t start = clock();
	double result;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
		list[j + 1] = key;
		
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf \n", result);
}

//선택
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	clock_t start = clock();
	double result;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 			// 최솟값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
		
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf \n", result);
}

//버블
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	clock_t start = clock();
	double result;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {	// 앞뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
			
		}
		
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf \n", result);
	
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
		
	}

}
//셸
void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	clock_t start = clock();
	double result;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) 
			gap++;
		for (i = 0; i < gap; i++) {		// 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
		}
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf \n", result);
}



int main() {

	int list[SIZE], insertion[SIZE], selection[SIZE], bubble[SIZE], sell[SIZE];

	int random;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		random = rand() % 1000000 + 1;
		list[i] = random;
		insertion[i] = random; // 삽입
		selection[i] = random; //선택
		bubble[i] = random;	//버블
		sell[i] = random;	//셸
	}


	printf("삽입정렬: ");
	insertion_sort(insertion, SIZE);

	printf("-----------------------------------------------\n");

	printf("선택정렬: ");
	selection_sort(selection, SIZE);

	printf("-----------------------------------------------\n");

	printf("버블정렬: ");
	bubble_sort(bubble, SIZE);

	printf("-----------------------------------------------\n");

	printf("셸정렬: ");
	shell_sort(sell, SIZE);


}