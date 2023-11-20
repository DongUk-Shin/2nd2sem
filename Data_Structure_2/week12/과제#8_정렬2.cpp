#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define SIZE 30000

// ��������
void insertion_sort(int list[], int n)
{
	int i, j, key;
	clock_t start = clock();
	double result;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; 		// ���ڵ��� ������ �̵�
		list[j + 1] = key;
		
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf \n", result);
}

//����
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	clock_t start = clock();
	double result;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 			// �ּڰ� Ž��
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
		
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf \n", result);
}

//����
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	clock_t start = clock();
	double result;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {	// �յ��� ���ڵ带 ���� �� ��ü
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
			
		}
		
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf \n", result);
	
}

//��
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
//��
void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	clock_t start = clock();
	double result;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) 
			gap++;
		for (i = 0; i < gap; i++) {		// �κ� ����Ʈ�� ������ gap
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
		insertion[i] = random; // ����
		selection[i] = random; //����
		bubble[i] = random;	//����
		sell[i] = random;	//��
	}


	printf("��������: ");
	insertion_sort(insertion, SIZE);

	printf("-----------------------------------------------\n");

	printf("��������: ");
	selection_sort(selection, SIZE);

	printf("-----------------------------------------------\n");

	printf("��������: ");
	bubble_sort(bubble, SIZE);

	printf("-----------------------------------------------\n");

	printf("������: ");
	shell_sort(sell, SIZE);


}