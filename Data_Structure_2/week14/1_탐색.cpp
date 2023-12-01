#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200000

int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
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
			return i; // Ž�� ����
	}
	return -1;    	// Ž�� ����
}

int compare_count_binary = 0;
int search_binary2(int key, int low, int high, int list[])
{
	int middle;
	while (low <= high) { 				// ���� ���ڵ��� ���� ������
		middle = (low + high) / 2;
		compare_count_binary++;
		if (key == list[middle])
			return middle; 	// Ž�� ����
		else if (key > list[middle])
			low = middle + 1; 	// ���� �κи���Ʈ Ž��
		else
			high = middle - 1; 			// ������ �κи���Ʈ Ž��
	}
	return -1; 					// Ž�� ����
}

int main() {
	srand(time(NULL));
	int list[MAX];

	for (int i = 0; i < MAX; i++) {
		list[i] = rand() % MAX + 1;
	}
	int key = rand() % MAX + 1;

	clock_t start1 = clock(); double result1;
	printf("\nkey:%d\t��Ƚ��:%d\t����Ʈ�� �ε���:%d", key, compare_count_seq, seq_search(key, 0, MAX, list));
	clock_t end1 = clock(); result1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\n���� Ž�� �ð� %lf \n", result1);

	qsort(list, sizeof(list) / sizeof(int), sizeof(int), compare);

	clock_t start2 = clock(); double result2;
	printf("\nkey:%d\t��Ƚ��:%d\t����Ʈ�� �ε���:%d", key, compare_count_binary, search_binary2(key, 0, MAX, list));
	clock_t end2 = clock(); result2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\n���� Ž�� �ð� %lf \n", result2);

}

