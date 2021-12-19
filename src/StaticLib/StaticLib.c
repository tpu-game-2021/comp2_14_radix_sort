#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
     item items[100];
    for (int d = 0, r = 1; d < 5; d++, r *= 10)
    {
        for (int i = 0; i < begin->key; i++)
        {
            
        }
        if (begin == NULL || end == NULL)
        {
            return false;
        }
    }
	// ToDo: 基数ソートを実装する
	
}
