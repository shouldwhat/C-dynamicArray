#pragma once

typedef struct Book
{
	char b_name[20 + 1];
	int isbn;
}Book;

Book *Book_newBook(char *name, int isbn);
void Book_Delete(Book *book);
char *Book_GetName(Book *book);
int Book_GetIsbn(Book *book);
void Book_ViewBook(Book *book);