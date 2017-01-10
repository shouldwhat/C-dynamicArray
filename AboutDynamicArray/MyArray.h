#pragma once

typedef void* Element;
typedef struct MyArray MyArray;

struct MyArray
{
	Element *base;
	int capacity;
	int cnt;
};

MyArray *MyArray_newArray(int asize);
void MyArray_Delete(MyArray *Array);
void MyArray_Add(MyArray *Array, Element data);
int MyArray_GetCnt(MyArray *Array);
Element MyArray_GetAt(MyArray *Array, int index);
void MyArray_Insert(MyArray *Array, int index, Element data);
void MyArray_Erase(MyArray *Array, int index);
void MyArray_Clear(MyArray *Array);
void MyArray_SetAt(MyArray *Array, int index, Element data);
int MyArray_GetMax(MyArray *Array);