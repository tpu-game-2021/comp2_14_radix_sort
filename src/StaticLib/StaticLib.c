#define WIN32_LEAN_AND_MEAN  // Windows ヘッダーからほとんど使用されていない部分を除外する
#define RADIX 256
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>
#include "../include/lib_func.h"

int findMax(item* begin, const item* end)
{
    int num = end - begin;
    int Max = begin[0].key;

    for (int i = 0; i < num; i++) 
    {
        if (begin[i].key > Max) 
        {
            Max = begin[i].key;
        }
    }

    return Max;
}


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	// ToDo: 基数ソートを実装する
	if (begin == NULL || end == NULL)  return false;
    if (end < begin)  return false;
    if (end - begin == 1)  return true;

    int Max = findMax(begin, end);  // ここで最大値を取得する
    int Rank = 1;  // 桁数
    int num = end - begin;  // 要素数
    int* rad = (int*)malloc(sizeof(int) * num);
    item* temp = (item*)malloc(sizeof(item) * num);

    while (Rank <= Max) 
    {
        for (int i = 0; i < num; i++)
        {
            rad[i] = (begin[i].key / Rank) % RADIX;
        }

        int k = 0;

        for (int i = 0; i < RADIX; i++)  //バケツ、0～255
        {
            for (int j = 0; j < num; j++) 
            {
                if (rad[j] == i) 
                {
                    temp[k] = begin[j];
                    k++;
                }
            }
        }
        for (int i = 0; i < num; i++)
        {
            begin[i] = temp[i];
        }

        Rank *= RADIX;
    }

    free(rad);
    free(temp);
    return true;
}
