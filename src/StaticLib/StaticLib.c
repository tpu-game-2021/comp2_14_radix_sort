#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include "stdlib.h"
#include "malloc.h"
#include "../include/lib_func.h"


int find_Max(item* begin, const item* end)
{
	int num = end - begin;//要素数
	int Max = begin[0].key;//最大値
	for (int i = 0; i < num; i++)//比較
	{
		if (begin[i].key > Max)//最大値と比較
		{
			Max = begin[i].key;//beginが大きい場合比較
		}
	}
	return Max;//最大値返却
}
// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	if (end < begin)
		return false;
	if (end == NULL || begin == NULL)//NULLの返り値がNULLの場合はじく
		return false;
	if (end - begin == 1)//1要素はソートしない
		return true;

	int Max = find_Max(begin, end);//最大値取得
	int num = end - begin;
	int m = 1;//基数を取り出す値(1,10,100の桁を取り出す場合に必要)
	int* rad = (int*)malloc(sizeof(int) * num); //アドレス確保のおまじない
	item* temp = (item*)malloc(sizeof(item) * num);
	while (m <= Max) //桁の数まで
	{
		for (int i = 0; i < num; i++) //要素数分繰り返す
		    rad[i] = (begin[i].key / m) % 256;

		int k = 0;//繰り上げの配列として使う
		for (int i = 0; i < 256; i++)//バケツ0～255
			for (int j = 0; j < num; j++)//要素数分繰り返す
			if (rad[j] == i)//小さい順
				temp[k++] = begin[j];//tempの配列にコピー

		for (int i = 0; i < num; i++)//要素数分コピー
			begin[i] = temp[i];//beginに配列コピー

		m *= 256;//桁の繰り上げ
	}
	free(rad);//mallocとセットで書く
	free(temp);
	// ToDo: 基数ソートを実装する
	return true;
}
