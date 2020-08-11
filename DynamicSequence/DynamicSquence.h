#pragma once
// 顺序表动态存储
typedef int DataType; // 用DtaType 代替int

typedef struct DSequence {
	DataType* arr;
	size_t size;
	size_t capacity;
} DSequence;

//初始化 
void DSequenceInit(DSequence* ds1);
// 检测容量
void CheckDS(DSequence* ds);
// 尾插
void PushBack(DSequence* ds, int val);

//插入
void Insert(DSequence* ds, size_t pos, int val);

//删除
void Erase(DSequence* ds, size_t pos);

//头插
void PushHead(DSequence* ds, int val);
// 打印
void Print(DSequence* ds);

//销毁
void DSequenceDestory(DSequence* ds);
