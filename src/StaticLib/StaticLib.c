#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	if (begin == NULL || end == NULL) return false;
	if (begin > end) return false;
	// ToDo: 基数ソートを実装する

	int max = begin->key;
	int size = end - begin;
	for (item* it = begin; it != end; it++)
		if (max < it->key) max = it->key; // 最大値の検索

	for (int m = 1; m < max; m *= 256) {
		int count[256] = { 0 };
		for (item* it1 = begin; it1 != end; it1++) // バケツごとの要素数
		{
			int num = it1->key / m % 256;
			count[num]++;
		}

		int l = 0;
		for (int i = 0; i < 256; i++) {
			item* it1 = begin;
			int  k = 0;
			for (int j = 0, k = 0; k < count[i] && j < size; j++, it1++) {
				if (it1->key / m % 256 == i) {
					item temp = begin[l];
					begin[l] = *it1;
					*it1 = temp;
					l++;
					k++;
				}
			}
		}
	}
	return true;
}

