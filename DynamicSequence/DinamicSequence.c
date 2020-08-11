#include <stdio.h>
#include <stdlib.h>
#include "DynamicSquence.h"

// ��ʼ����̬����
void DSequenceInit(DSequence* ds) {
	ds->size = 0;
	ds->capacity = 4;
	ds->arr = (int*)malloc(sizeof(DataType)*4);
}

//�������
void CheckDS(DSequence* ds) {
	if (ds->size == ds->capacity) { // ���������
		ds->capacity *= 2;
		DataType* NewArr = (int*)malloc(sizeof(DataType)*ds->capacity);
		(int)memcpy(NewArr, ds->arr, sizeof(DataType)*ds->size);
		free(ds->arr);
		ds->arr = NewArr;
	}
}
// β��
void PushBack(DSequence* ds, int val) {
	// ����ǰ�������
	CheckDS(ds);
	ds->arr[ds->size] = val;  //ԭ���������һ���±�Ϊ size-1�����Բ���sizeλ�ã������size++
	ds->size++;
}
// ����λ�ò���
void Insert(DSequence* ds, size_t pos, int val) {  //����posǰ���λ�ã�pos���±�
	if (pos <= ds->size) {
		CheckDS(ds);
		size_t n = ds->size;
		while (n > pos) {
			ds->arr[n] = ds->arr[n - 1];
			n--;
		}
		ds->arr[pos] = val;
		ds->size++;
	}
}

void Erase(DSequence* ds, size_t pos) {
	if (pos <= ds->size) {
		CheckDS(ds);
		size_t n = ds->size - 1;
		while (pos < n) {
			ds->arr[pos] = ds->arr[pos + 1];
			pos++;
		}
		ds->size--;
	}
}

// ͷ��
void PushHead(DSequence* ds, int val) {
	CheckDS(ds);
	int n = ds->size;
	while (n) {  // Ԫ�������ƶ�
		ds->arr[n] = ds->arr[n - 1];
		n--;
	}
	ds->arr[0] = val;
	ds->size++;
}

// ��ӡ
void Print(DSequence* ds) {
	for (size_t i = 0; i < ds->size; i++) {
		printf("%d ", ds->arr[i]);
	}
	printf("\n");
}

// ����
void DSequenceDestory(DSequence* ds) {
	ds->arr = 0;
	ds->capacity = 0;
	ds->arr = NULL;
	free(ds->arr);
}