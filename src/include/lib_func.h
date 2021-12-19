#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct item_
	{
		unsigned int key;
		char value[256];
	}item;

	typedef struct bucket_
	{
		int zero[256];
		int one[256];
		int two[256];
		int three[256];
		int four[256];
		int five[256];
		int six[256];
		int seven[256];
		int eight[256];
		int nine[256];

	}bucket;

	// 基数ソート(引数が不適切であればfalseを返す)
	// 基数は256で実装せよ
	bool radix_sort(item *begin, const item* end);

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
