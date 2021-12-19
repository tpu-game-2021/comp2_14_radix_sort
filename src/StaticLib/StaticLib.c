#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ

int find_max(item* begin, const item* end,const int radix)
{
	int max = begin[0].key;
	int elements = begin - end;

	for (int i = 0; i < elements; i++) {
		max = begin[i].key > max ? begin[i].key : max;
	}
	return (int)(log10(max)/log10(radix));
}

bool radix_sort(item* begin, const item* end)
{
	// ToDo: 基数ソートを実装する
	if (begin == NULL || end == NULL || end < begin)return false;

	const int radix = 256;//基数
	int max = find_max(begin, end, radix);//最大値の桁数
	int digits = 0;//桁数
	int elements = end - begin;//要素数
	item* rad = (item*)malloc(sizeof(item) * elements);//基数をしまう配列
	item* temp = (item*)malloc(sizeof(item) * elements);//入れ替え用の配列

	while (digits <= max) {
		for (int i = 0; i < elements; i++) {
			rad[i].key = (begin[i].key / (int)pow(radix, digits)) % radix;//基数を取り出しrad[i]に保存
		}
		int k = 0;//添え字
		for (int i = 0; i < radix; i++) {
			for (int j = 0; j < elements; j++) {
				if (rad[j].key == i) {
					temp[k++] = begin[j];//基数の小さいものからtempにコピー
				}
			}
		}
		for (int i = 0; i < elements; i++) {
			begin[i] = temp[i];//beginにコピー
		}
		digits++;
	}
	free(rad);
	free(temp);
	return true;
}
