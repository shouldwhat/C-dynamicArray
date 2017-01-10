#pragma warning(disable:4996)

#include "Book.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Book *Book_newBook(char *name, int isbn)
{
	Book *newBook = (Book *)malloc(sizeof(Book));

	newBook->isbn = isbn;
	strcpy(newBook->b_name, name);
	return newBook;
}
int Book_GetIsbn(Book *book)
{
	return book->isbn;
}
char *Book_GetName(Book *book)
{
	return book->b_name;
}
void Book_ViewBook(Book *book)
{
	printf("å �� �� : %s\n", book->b_name);
	printf("�Ϸù�ȣ : %d\n", book->isbn);
}
void Book_Delete(Book *book)
{
	free(book);
}