#pragma once
#pragma warning(disable:4996)

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Genre.h"
#include "Book.h"

Genre *Genre_newGenre(const char *name, int num)
{
	Genre *newGenre = (Genre *)malloc(sizeof(Genre));

	strcpy(newGenre->g_name, name);
	newGenre->g_num = num;
	newGenre->books = MyArray_newArray(0);

	return newGenre;
}
void Genre_Delete(Genre *genre)
{
	free(genre);
}

char *Genre_GetName(Genre *genre)
{
	return genre->g_name;
}
void Genre_AddBook(Genre *genre, char *name, int isbn)
{
	Book *book = 0;
	int index = 0;
	int max;
	int flag;

	book = Book_newBook(name, isbn);
	max = MyArray_GetCnt(genre->books);

	flag = Genre_FindBook(genre, isbn, max);

	if (flag != -1)
	{
		printf("해당 책이 존재 합니다.\n");
	}
	else
	{
		MyArray_Add(genre->books, book);
	}
}
void Genre_ViewBookAll(Genre *genre, int b_num)
{
	int n = 0;
	Book *book;

	printf("[%s]\n", Genre_GetName(genre));
	for (n = 0; n<b_num; n++)
	{
		book = (Book *)MyArray_GetAt(genre->books, n);
		Book_ViewBook(book);
	}
	printf("\n");
}
int Genre_FindBook(Genre *genre, int isbn, int cnt)
{
	int index = 0;
	Book *book;

	for (index; index<cnt; index++)
	{
		book = (Book *)MyArray_GetAt(genre->books, index);
		if (book->isbn == isbn)
		{
			Book_ViewBook(book);
			return 0;
		}
	}
	return -1;
}


