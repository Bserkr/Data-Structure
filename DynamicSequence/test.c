#include <stdio.h>
#include <stdlib.h>
#include "DynamicSquence.h";

void test() {
	DSequence ds1;
	DSequenceInit(&ds1);
	PushBack(&ds1, 1);
	PushBack(&ds1, 2);
	PushBack(&ds1, 3);
	PushBack(&ds1, 4);
	PushHead(&ds1, 5);
	PushHead(&ds1, 6);
	PushHead(&ds1, 7);
	Print(&ds1);

	Insert(&ds1, 2, 10);
	Print(&ds1);

	Erase(&ds1, 1);
	Print(&ds1);
}

int main() {
	test();



	system("pause");
	return 0;
}