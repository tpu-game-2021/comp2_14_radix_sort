#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include<stdlib.h>
#include "malloc.h"

bool radix_sort(item* begin, const item* end)
{
    int i, j, k;

    if (end == NULL || begin == NULL || end < begin)
    {
        return false;
    }
    if (end - begin == 1)
    {
        return true;
    }

    int Max = begin[0].key;
    int num = end - begin;
    int m = 1;
    int* secure = (int*)malloc(sizeof(int) * num); 
    item* temp = (item*)malloc(sizeof(item) * num);

    while (m <= Max) 
    {
        for (i = 0; i < num; i++)
        {
            secure[i] = (begin[i].key / m) % 256;   /* 基数を取り出し rad[i] に保存 */
        }

        k = 0;                          /* 配列の添字として使う */
        for (i = 0; i <= 256; i++)/* 基数は0から9 */
        {
            for (j = 0; j < num; j++)
            {
                if (secure[j] == i)/* 基数の小さいものから */
                {
                    temp[k++] = begin[j];      /* y[ ] にコピー */
                }
            }
        }

        for (i = 0; i < num; i++)
        {
            begin[i] = temp[i];                /* x[ ] にコピーし直す */
        }

        m *= 256;                        /*  基数を取り出す桁を一つ上げる */
    }

    free(secure);
    free(temp);
	return true;
}
