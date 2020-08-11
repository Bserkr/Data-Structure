#pragma once
// ˳���̬�洢
typedef int DataType; // ��DtaType ����int

typedef struct DSequence {
	DataType* arr;
	size_t size;
	size_t capacity;
} DSequence;

//��ʼ�� 
void DSequenceInit(DSequence* ds1);
// �������
void CheckDS(DSequence* ds);
// β��
void PushBack(DSequence* ds, int val);

//����
void Insert(DSequence* ds, size_t pos, int val);

//ɾ��
void Erase(DSequence* ds, size_t pos);

//ͷ��
void PushHead(DSequence* ds, int val);
// ��ӡ
void Print(DSequence* ds);

//����
void DSequenceDestory(DSequence* ds);
