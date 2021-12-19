#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	if (end - begin < 0)return false;
	if (begin == NULL || end == NULL)return false;
	int i, j, k,l;
	int digit=1;
	int* bucket;
	item* tmp;
	bucket = (int*)malloc((sizeof(int) * (end - begin)));
	tmp = (item*)malloc(sizeof(item) * (end - begin));
	for (i = 0; i < 4; i++)							//256進数であればint型は4回で完了
	{
		for (j = 0; j < end - begin; j++)
		{
			bucket[j] = (begin[j].key/ digit) % 256;//256進数での桁を参照するための配列を作成
		}
		l = 0;
		for (j = 0; j < 256; j++){					//作った配列を参考にソートするデータを並び替え
			for (k = 0; k < end - begin; k++){
				if (bucket[k] == j)
					tmp[l++] = begin[k];
			}
			if (l == end - begin)break;
		}
		for (j = 0; j < end - begin; j++)			//元のデータに反映させる。
		{
			begin[j] = tmp[j];
		}
		digit *= 256;								//参照する桁を上げる
	}
	free(bucket);
	free(tmp);
	return true;
}
