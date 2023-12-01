#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE	10	// 탐색키의 최대길이  
#define VALUE_SIZE	14	// 탐색키의 최대길이  
#define TABLE_SIZE	10	// 해싱 테이블의 크기=소수 

typedef struct
{
	char key[KEY_SIZE];
	char value[VALUE_SIZE];
} element;

element hash_table[TABLE_SIZE];		// 해싱 테이블 


// 문자로 된 키를 숫자로 변환
int transform(char* key) {
	int number = 0;

	while (*key) {
		number = number + *key++;
	}
	return number;
}
// 제산 함수를 사용한 해싱 함수
int hash_function(char* key)
{
	// 키를 자연수로 변환한 다음 테이블의 크기로 나누어 나머지를 반환
	return transform(key) % TABLE_SIZE;
}

//이중해싱법
int hash_function2(char* key) {
	return (7 - (transform(key) % 7));
}

#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key,item2.key))


// 테이블이 가득 찬 경우는 종료     
void hash_dh_add(element item, element ht[]) {
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key);

	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}
		i = (i + inc) % TABLE_SIZE;

		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다.\n");
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
			printf("탐색 %s 성공 %s\n", item.key, item.value);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			printf("찾는 값이 테이블에 없음\n");
			return;
		}
	}
	printf("찾는 값이 테이블에 없음\n");
	return;
}

// 해싱 테이블의 내용을 출력
void hash_lp_print(element ht[])
{
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
	printf("===============================\n\n");
}


// 해싱 테이블을 사용한 예제 
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
