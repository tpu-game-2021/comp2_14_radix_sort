#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	if (begin == NULL)
		return false;
	if (end == NULL)
		return false;

	int n = (end - begin);

	int i,j;
	bucket buckets[256];

	for (i = 0; i < 256; i++) 
	{
		for (j = 0; j < n; j++)
		{
			switch(begin[j] % (10^(i + 1))
			{
			default:
				break;
			}
		}

	
	}



	// ToDo: 基数ソートを実装する
	return false;
}
