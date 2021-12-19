#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "stdlib.h"
#include "malloc.h"

#include "../include/lib_func.h"

// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
    if (end < begin || end == NULL || begin == NULL)
    {
        return false;
    }

    if (end - begin == 1)
    {
        return true;
    }

    int max = begin[0].key;
    int num = end - begin;

    for (int i = 0; i < num; i++)
    {
        if (begin[i].key > max)
        {
            max = begin[i].key;
        }
    }

    int m = 1;

    //アドレス確保
    int* rad = (int*)malloc(sizeof(int) * num);

    item* temp = (item*)malloc(sizeof(item) * num);

    //ループ
    while (m <= max)
    {
        //1
        for (int i = 0; i < num; i++)
        {
            rad[i] = (begin[i].key / m) % 256;
        }

        int k = 0;

        //2
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (rad[j] == i)
                {
                    temp[k++] = begin[j];
                }
            }
        }

        //3
        for (int i = 0; i < num; i++)
        {
            begin[i] = temp[i];
        }

        m *= 256;
    }

    free(rad);
    free(temp);

    // ToDo: 基数ソートを実装する
    return true;
}
