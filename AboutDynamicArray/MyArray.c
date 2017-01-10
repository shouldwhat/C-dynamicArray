#include <malloc.h>

#include "MyArray.h"

void MyArray_Array(MyArray *Array, int asize);
void MyArray_DeleteArray(MyArray *Array);
int MyArray_IsFull(MyArray *Array);
int MyArray_IsAvail(MyArray *Array, int index);
void MyArray_ShiftRight(MyArray *Array, int index);
void MyArray_ShiftLeft(MyArray *Array, int index);
void MyArray_Resize(MyArray *array, int n_capacity);

MyArray* MyArray_newArray(int capacity)
{
	MyArray *array = (MyArray *)malloc(sizeof(MyArray));
	MyArray_Array(array, capacity);

	return array;
}

void MyArray_Delete(MyArray *Array)
{
	MyArray_DeleteArray(Array);
	free(Array);
}

void MyArray_Add(MyArray *array, Element data)
{
	if (MyArray_IsFull(array))
	{
		if (array->capacity == 0)
		{
			MyArray_Resize(array, 1);
		}
		else
		{
			MyArray_Resize(array, array->capacity * 2);
		}
	}
	array->base[array->cnt] = data;
	array->cnt++;
}

int MyArray_GetCnt(MyArray *array)
{
	return array->cnt;
}

Element MyArray_GetAt(MyArray *array, int index)
{
	if (MyArray_IsAvail(array, index))
	{
		return array->base[index];
	}
	return 0;
}

void MyArray_Insert(MyArray *array, int index, Element data)
{
	if (MyArray_IsFull(array))
	{
		if (array->capacity == 0)
		{
			MyArray_Resize(array, 1);
		}
		else
		{
			MyArray_Resize(array, array->capacity * 2);
		}
	}
	MyArray_ShiftRight(array, index);
	array->base[index] = data;
	array->cnt++;
}

void MyArray_Erase(MyArray *array, int index)
{
	if (MyArray_IsAvail(array, index))
	{
		array->cnt--;
		MyArray_ShiftLeft(array, index);
	}
}

void MyArray_Clear(MyArray *array)
{
	array->cnt = 0;
}

void MyArray_SetAt(MyArray *array, int index, Element data)
{
	if (MyArray_IsAvail(array, index))
	{
		array->base[index] = data;
	}
}

int MyArray_GetMax(MyArray *array)
{
	return array->capacity;
}
////////////////////// 내부 함수 ////////////////////////
void MyArray_Array(MyArray *array, int asize)
{
	array->capacity = asize;
	array->base = (Element *)malloc(sizeof(Element)*asize);
	array->cnt = 0;
}
void MyArray_DeleteArray(MyArray *array)
{
	free(array->base);
}
int MyArray_IsFull(MyArray *array)
{
	return array->capacity == array->cnt;
}
int MyArray_IsAvail(MyArray *Array, int index)
{
	return (index >= 0) && (index<Array->cnt);
}
void MyArray_ShiftRight(MyArray *array, int index)
{
	int dest = 0;
	for (dest = array->cnt; dest>index; dest--)
	{
		array->base[dest] = array->base[dest - 1];
	}
}
void MyArray_ShiftLeft(MyArray *array, int index)
{
	for (; index<array->cnt; index++)
	{
		array->base[index] = array->base[index + 1];
	}
}

void MyArray_Resize(MyArray *array, int n_capacity)
{
	array->base = (Element *)realloc(array->base, sizeof(Element)*n_capacity);
	array->capacity = n_capacity;
}