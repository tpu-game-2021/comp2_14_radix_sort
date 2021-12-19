#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// 基数ソート(引数が不適切であればfalseを返す)
// 基数は256で実装せよ
bool radix_sort(item* begin, const item* end)
{
	// ToDo: 基数ソートを実装する
	if (begin == NULL || end == NULL)return false;
	if (end < begin)return false;

	int i, j, k, count, digit = 0, m = 1;
	int val = end->key;
	int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0,
		count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;

	item* items0 = (item*)malloc(sizeof(item) * 256);
	item* items1 = (item*)malloc(sizeof(item) * 256);
	item* items2 = (item*)malloc(sizeof(item) * 256);
	item* items3 = (item*)malloc(sizeof(item) * 256);
	item* items4 = (item*)malloc(sizeof(item) * 256);
	item* items5 = (item*)malloc(sizeof(item) * 256);
	item* items6 = (item*)malloc(sizeof(item) * 256);
	item* items7 = (item*)malloc(sizeof(item) * 256);
	item* items8 = (item*)malloc(sizeof(item) * 256);
	item* items9 = (item*)malloc(sizeof(item) * 256);

	while (val != 0)
	{
		val = val / 10;
		digit++;
	}

	for (j = 0; j < digit; j++)
	{
		for (i = 0; i < end->key; i++)
		{
			switch ((begin + i)->key * m % 10)
			{
			case 0:
				items0[count0] = *(begin + i);
				count0++;
				break;
			case 1:
				items1[count1] = *(begin + i);
				count1++;
				break;
			case 2:
				items2[count2] = *(begin + i);
				count2++;
				break;
			case 3:
				items3[count3] = *(begin + i);
				count3++;
				break;
			case 4:
				items4[count4] = *(begin + i);
				count4++;
				break;
			case 5:
				items5[count5] = *(begin + i);
				count5++;
				break;
			case 6:
				items6[count6] = *(begin + i);
				count6++;
				break;
			case 7:
				items7[count7] = *(begin + i);
				count7++;
				break;
			case 8:
				items8[count8] = *(begin + i);
				count8++;
				break;
			case 9:
				items9[count9] = *(begin + i);
				count9++;
				break;
			}
		}
		m *= 10;

		count = 0;
		for (k = 0; k < count0; k++)
		{
			*(begin + count) = items0[k];
			count++;
		}
		for (k = 0; k < count1; k++)
		{
			*(begin + count) = items1[k];
			count++;
		}
		for (k = 0; k < count2; k++)
		{
			*(begin + count) = items2[k];
			count++;
		}
		for (k = 0; k < count3; k++)
		{
			*(begin + count) = items3[k];
			count++;
		}
		for (k = 0; k < count4; k++)
		{
			*(begin + count) = items4[k];
			count++;
		}
		for (k = 0; k < count5; k++)
		{
			*(begin + count) = items5[k];
			count++;
		}
		for (k = 0; k < count6; k++)
		{
			*(begin + count) = items6[k];
			count++;
		}
		for (k = 0; k < count7; k++)
		{
			*(begin + count) = items7[k];
			count++;
		}
		for (k = 0; k < count8; k++)
		{
			*(begin + count) = items8[k];
			count++;
		}
		for (k = 0; k < count9; k++)
		{
			*(begin + count) = items9[k];
			count++;
		}
	}
	free(items0);
	free(items1);
	free(items2);
	free(items3);
	free(items4);
	free(items5);
	free(items6);
	free(items7);
	free(items8);
	free(items9);
	return true;
}
