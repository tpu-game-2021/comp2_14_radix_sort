#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	// ToDo: 基数ソートを実装する
	if (begin == NULL || end == NULL)
		return false;
	if (end < begin)
		return false;
	if (end - begin == 1)
		return true;

	int num = end - begin;
	int rank=1;
	int max=begin[0].key;
	int k;
    int rad[256];
	item tempo[256];

	for (int i = 0; i < num; i++) {
		if (begin[i].key > max) {
			max = begin[i].key;
		}
	}

	while (rank<=max)
	{
		for (int i = 0; i < num; i++) {
			rad[i] = (begin[i].key / rank) % 10;
		}

		k = 0;
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < num; j++) {
				if (rad[j] == i) {
					tempo[k++] = begin[j];
				}
			}
		}

		for (int i = 0; i < num; i++)
			begin[i] = tempo[i];

		rank *= 10;
	}
	return true;
}