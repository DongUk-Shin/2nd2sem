#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE	10	// Ž��Ű�� �ִ����  
#define VALUE_SIZE	14	// Ž��Ű�� �ִ����  
#define TABLE_SIZE	10	// �ؽ� ���̺��� ũ��=�Ҽ� 

typedef struct
{
	char key[KEY_SIZE];
	char value[VALUE_SIZE];
} element;

element hash_table[TABLE_SIZE];		// �ؽ� ���̺� 


// ���ڷ� �� Ű�� ���ڷ� ��ȯ
int transform(char* key) {
	int number = 0;

	while (*key) {
		number = number + *key++;
	}
	return number;
}
// ���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char* key)
{
	// Ű�� �ڿ����� ��ȯ�� ���� ���̺��� ũ��� ������ �������� ��ȯ
	return transform(key) % TABLE_SIZE;
}

//�����ؽ̹�
int hash_function2(char* key) {
	return (7 - (transform(key) % 7));
}

#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key,item2.key))


// ���̺��� ���� �� ���� ����     
void hash_dh_add(element item, element ht[]) {
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key);

	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�.\n");
			exit(1);
		}
		i = (i + inc) % TABLE_SIZE;

		if (i == hash_value) {
			fprintf(stderr, "���̺��� ����á���ϴ�.\n");
			exit(1);
		}
	}
	ht[i] = item;
}

void hash_dh_search(element item, element ht[]) {
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			printf("Ž�� %s ���� %s\n", item.key, item.value);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			printf("ã�� ���� ���̺� ����\n");
			return;
		}
	}
	printf("ã�� ���� ���̺� ����\n");
	return;
}

// �ؽ� ���̺��� ������ ���
void hash_lp_print(element ht[])
{
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
	printf("===============================\n\n");
}


// �ؽ� ���̺��� ����� ���� 
int main(void)
{
	const char* name[10]= { 
		"Hong","Kim","Lee","Nam","Cheon",
		"Ahn","Park", "Shin","Oh","Gu" 
	};
	const char* number[10]= {
		"010-1234-0001","010-1234-0002",
		"010-1234-0003","010-1234-0004",
		"010-1234-0005","010-1234-0006",
		"010-1234-0007","010-1234-0008",
		"010-1234-0009","010-1234-0010"
	};

	element e;

	for (int i = 0; i < 10; i++) {
		strcpy_s(e.key, name[i]);
		strcpy_s(e.value, number[i]);

		hash_dh_add(e, hash_table);
	}

	hash_lp_print(hash_table);
	for (int i = 0; i < 10; i++) {
		strcpy_s(e.key, name[i]);
		strcpy_s(e.value, number[i]);

		hash_dh_search(e, hash_table);
	}
	return 0;
}
