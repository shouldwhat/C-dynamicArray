#pragma once

#include "MyArray.h"
#include "Book.h"

typedef struct Genre Genre;
struct Genre
{
	MyArray *books;
	int g_num;
	char g_name[20 + 1];
};

Genre *Genre_newGenre(const char *name, int num);
void Genre_Delete(Genre *genre);
char *Genre_GetName(Genre *genre);
void Genre_AddBook(Genre *genre, char *name, int isbn);
void Genre_ViewBookAll(Genre *genre, int b_num);
int Genre_FindBook(Genre *genre, int isbn, int cnt);