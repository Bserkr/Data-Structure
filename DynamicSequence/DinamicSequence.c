#include <stdio.h>
#include <stdlib.h>
#include "DynamicSquence.h"

// 初始化动态数组
void DSequenceInit(DSequence* ds) {
	ds->size = 0;
	ds->capacity = 4;
	ds->arr = (int*)malloc(sizeof(DataType)*4);
}

//检测容量
void CheckDS(DSequence* ds) {
	if (ds->size == ds->capacity) { // 相等了增容
		ds->capacity *= 2;
		DataType* NewArr = (int*)malloc(sizeof(DataType)*ds->capacity);
		(int)memcpy(NewArr, ds->arr, sizeof(DataType)*ds->size);
		free(ds->arr);
		ds->arr = NewArr;
	}
}
// 尾插
void PushBack(DSequence* ds, int val) {
	// 插入前检查容量
	CheckDS(ds);
	ds->arr[ds->size] = val;  //原本数组最后一个下标为 size-1，所以插入size位置，插入后size++
	ds->size++;
}
// 任意位置插入
void Insert(DSequence* ds, size_t pos, int val) {  //插入pos前面的位置，pos是下标
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

// 头插
void PushHead(DSequence* ds, int val) {
	CheckDS(ds);
	int n = ds->size;
	while (n) {  // 元素向右移动
		ds->arr[n] = ds->arr[n - 1];
		n--;
	}
	ds->arr[0] = val;
	ds->size++;
}

// 打印
void Print(DSequence* ds) {
	for (size_t i = 0; i < ds->size; i++) {
		printf("%d ", ds->arr[i]);
	}
	printf("\n");
}

// 销毁
void DSequenceDestory(DSequence* ds) {
	ds->arr = 0;
	ds->capacity = 0;
	ds->arr = NULL;
	free(ds->arr);
}