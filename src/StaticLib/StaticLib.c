#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#define Radix 256
#include "../include/lib_func.h"
#include<stdlib.h>


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ

bool radix_sort(item* begin, const item* end)
{
	// ToDo: 基数ソートを実装する
	int num = end - begin;//要素数
	int Max = begin[0].key;
	int baket[Radix];
	int j=0, k=0, i=0;
	item box[Radix];

	if (begin == NULL || end == NULL)
		return false;
	if (end < begin)
		return false;


	for ( i = 0; i < num; i++)
	{
		if (begin[i].key > Max)
		{
			Max = begin[i].key;
		}
	}

	for (i = 0; i < num; i++)
	{
		baket[i] = (begin[i].key / 1) % 10;
	}
	for (i = 0; i < Radix; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (baket[j] == i)
			{
				box[k] = begin[i];
				k++;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		begin[i] = box[i];
	}
	
	
	

	return true;
}
