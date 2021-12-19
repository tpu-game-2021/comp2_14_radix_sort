#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include<stdlib.h>

#define RADIX 256

int comparison(item* begin,const item* end)
{
	int number = end - begin;//number of elements
	int stand = begin[0].key; //standard
	for (int i = 0; i < number; i++)
		if (begin[i].key > stand)
			stand = begin[i].key; //copy to stand
	return stand;
}
// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	// ToDo: 基数ソートを実装する
	if (begin == NULL || end == NULL || end < begin) return false;
	if (end - begin == 1)return true;

	int take = 1; //digit
	int number = end - begin; //number of elements
	int* box = (int*)malloc(sizeof(int) * number); //array of randix
	item* subbox = (item*)malloc(sizeof(item) * number); //array of destinatino
	int stand = comparison(begin, end); //maximum value
	while (take <= stand)
	{
		for (int i = 0; i < number; i++) 
			box[i] = (begin[i].key / take) % RADIX; //save to box
		int sub = 0; //subscript
		for (int i = 0; i < RADIX; i++)
			for (int j = 0; j < number; j++)
				if (box[j] == i)
					subbox[sub++] = begin[j]; //copy to subbox
		for (int i = 0; i < number; i++) begin[i] = subbox[i]; //recopy to begin
		take *= RADIX; //raise the radix by one digit
	}
	free(box); //free up memory
	free(subbox); //free up memoty
	return true;
}
