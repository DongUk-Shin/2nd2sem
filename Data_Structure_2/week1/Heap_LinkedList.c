#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int key;
    // 다른 필요한 데이터 필드를 추가할 수 있습니다.
} element;

typedef struct ListNode {
    element data;
    struct ListNode* next;
} ListNode;

typedef struct HeapType {
    int heap_size;
    ListNode* head;
} HeapType;

// 연결 리스트에 새로운 노드를 추가하는 함수
ListNode* createNode(element item) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

void insert_min_heap(HeapType* h, element item) {
    ListNode* newNode = createNode(item);

    if (h->head == NULL) {
        h->head = newNode;
        h->heap_size++;
        return;
    }

    // 연결 리스트 민 힙에 요소를 추가하고 필요한 순서로 재배열
    ListNode* current = h->head;
    ListNode* parent = NULL;

    while (current != NULL && item.key > current->data.key) {
        parent = current;
        current = current->next;
    }

    if (parent == NULL) {
        newNode->next = h->head;
        h->head = newNode;
    } else {
        parent->next = newNode;
        newNode->next = current;
    }

    h->heap_size++;
}

// 연결 리스트 민 힙에서 최소 요소를 삭제하고 반환하는 함수
element delete_min_heap(HeapType* h) {
    if (h->heap_size == 0) {
        perror("Heap is empty");
        exit(EXIT_FAILURE);
    }

    element min_element = h->head->data;
    ListNode* temp = h->head;
    h->head = h->head->next;
    free(temp);

    h->heap_size--;

    return min_element;
}
// 연결 리스트의 모든 요소를 출력하는 함수
void print_linked_list(HeapType* h) {
    ListNode* current = h->head;
    while (current != NULL) {
        printf("%d ", current->data.key);
        current = current->next;
    }
    printf("\n");
}

int main() {
    HeapType heap = {0, NULL};

    element item1 = {3};    
    element item2 = {1};
    element item3 = {5};
    element item4 = {2};
    
    insert_min_heap(&heap, item1);
    insert_min_heap(&heap, item2);
    insert_min_heap(&heap, item3);
    insert_min_heap(&heap, item4);

    print_linked_list(&heap);
    printf("Deleted min element: %d\n", delete_min_heap(&heap).key);
    printf("Deleted min element: %d\n", delete_min_heap(&heap).key);
    print_linked_list(&heap);
    return 0;
}
