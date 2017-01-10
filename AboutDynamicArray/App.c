#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "App.h"
#include "ehcommon.h"
#include "Genre.h"
#include <stdlib.h>
#define MAX 20

int SelectMenu();
void App_AddGenre(App *app);
void App_DelGenre(App *app);
void App_ListGenre(App *app);
void App_AddBook(App *app);
void App_DelBook(App *app);
void App_AllView(App *app);
void App_ViewBooksAtGenre(App *app);
void App_FindBookByIsbn(App *app);
int App_FindGenre(App *app, char *name, int cnt);

App *App_newApp()
{
	App *newApp = (App *)malloc(sizeof(App));

	newApp->genres = MyArray_newArray(0);
	newApp->g_num = 0;

	return newApp;
}
void App_Delete(App *app)
{
	free(app);
}
void App_Run(App *app)
{
	int key;

	while (1)
	{
		key = SelectMenu();

		switch (key)
		{
			case F1:App_AddGenre(app); break;
			case F2:App_DelGenre(app); break;
			case F3:App_ListGenre(app); break;
			case F4:App_AddBook(app); break;
			case F5:App_DelBook(app); break;
			case F6:App_AllView(app); break;
			case F7:App_ViewBooksAtGenre(app); break;
			case F8:App_FindBookByIsbn(app); break;
			case ESC:return;
			default: printf("�ٽ� �Է��ϼ���.\n");
		}

		getkey();
	}
}
int SelectMenu()
{
	system("cls");
	printf("���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�\n");
	printf("��   �帣�� ���� ���� ���α׷� - Show ��\n");
	printf("��                         2014. 5.12 ��\n");
	printf("��                         by. ����� ��\n");
	printf("���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�\n");
	printf(" F1: �帣 �߰�\n");
	printf(" F2: �帣 ����\n");
	printf(" F3: �帣 ��� ����\n");
	printf(" F4: ���� �߰�\n");
	printf(" F5: ���� ����\n");
	printf(" F6: ��� å ���\n");
	printf(" F7: ���� �帣 ���� ���\n");
	printf(" F8: ISBN���� ���� �˻�\n");

	return getkey();
}

void App_AddGenre(App *app)
{
	char name[MAX + 1];
	Genre *genre;
	int flag;

	printf("\n�߰��� �帣 �̸��� �Է��ϼ���.\n");
	getstr(name, MAX);

	flag = App_FindGenre(app, name, app->g_num);

	if (flag != -1)
	{
		printf("���� �帣�� ���� �մϴ�\n");
		return;
	}
	else
	{
		genre = Genre_newGenre(name, (app->g_num) + 1);
		MyArray_Add(app->genres, genre);
		app->g_num++;
	}

	printf("�ƹ� Ű�� ��������.\n");
}
void App_DelGenre(App *app)
{
	char g_name[MAX + 1];
	int index;
	Genre *genre;

	printf("������ �帣���� �Է��ϼ���.\n");
	getstr(g_name, MAX);

	index = App_FindGenre(app, g_name, app->g_num);
	if (index == -1)
	{
		printf("�ش� �帣�� �������� �ʽ��ϴ�.\n");
		return;
	}
	genre = (Genre *)MyArray_GetAt(app->genres, index);
	free(genre);

	printf("�ƹ� Ű�� ��������.\n");
}
void App_ListGenre(App *app)
{
	int g_cnt, n = 0;
	Genre *genre;

	printf("\n");
	g_cnt = app->g_num;
	if (app->g_num == 0)
		printf("\n�����ϴ� �帣�� �����ϴ�\n");
	else
	{
		for (n = 0; n<g_cnt; n++)
		{
			genre = (Genre *)MyArray_GetAt(app->genres, n);
			printf("%d��: %s\n", n + 1, Genre_GetName(genre));
		}
	}
	printf("�ƹ� Ű�� ��������.\n");
}
void App_AddBook(App *app)
{
	char g_name[MAX + 1];
	char b_name[MAX + 1];
	int b_isbn;
	int index;

	printf("�߰��� ���ϴ� �帣�� �Է��ϼ���.\n");
	getstr(g_name, MAX);

	index = App_FindGenre(app, g_name, app->g_num);
	if (index == -1)
	{
		printf("\n�ش� �帣�� �������� �ʽ��ϴ�.\n");
		return;
	}
	else
	{
		printf("å ������ �Է��ϼ���.\n");
		getstr(b_name, MAX);
		printf("å�� ISBN�� �Է��ϼ���.\n");
		b_isbn = getnum();

		Genre_AddBook((Genre *)MyArray_GetAt(app->genres, index), b_name, b_isbn);
	}
	printf("�ƹ� Ű�� ��������.\n");
}
void App_DelBook(App *app)
{
	printf("���� ���� �Լ� ����\n");
}
void App_AllView(App *app)
{
	Genre *genre;
	int n;

	for (n = 0; n<app->g_num; n++)
	{
		genre = (Genre *)MyArray_GetAt(app->genres, n);
		Genre_ViewBookAll(genre, genre->books->cnt);
	}

	printf("�ƹ� Ű�� ��������.\n");
}
void App_ViewBooksAtGenre(App *app)
{
	char g_name[MAX + 1];
	int index;
	int n = 0;
	Genre *genre;

	printf("���ϴ� �帣�� �Է��ϼ���.\n");
	getstr(g_name, MAX);
	index = App_FindGenre(app, g_name, app->g_num);

	if (index == -1)
	{
		printf("\n�ش� �帣�� �������� �ʽ��ϴ�.\n");
		return;
	}
	else
	{
		genre = (Genre *)MyArray_GetAt(app->genres, index);
		Genre_ViewBookAll(genre, genre->books->cnt);
	}
	printf("�ƹ� Ű�� ��������.\n");
}
void App_FindBookByIsbn(App *app)
{
	int isbn, flag;
	char g_name[MAX + 1];
	int index;
	Genre *genre;

	printf("�帣���� �Է��ϼ���.\n");
	getstr(g_name, MAX);

	index = App_FindGenre(app, g_name, app->g_num);

	if (index == -1)
	{
		printf("\n�ش� �帣�� �������� �ʽ��ϴ�.\n");
		return;
	}
	else
	{
		genre = (Genre *)MyArray_GetAt(app->genres, index);
		printf("ã������ ISBN�� �Է��ϼ���.\n");
		isbn = getnum();
		flag = Genre_FindBook(genre, isbn, genre->books->cnt);

		if (flag == -1)
			printf("\n�ش� å�� �������� �ʽ��ϴ�.\n");

	}
	printf("�ƹ� Ű�� ��������.\n");
}


/////////////////////////////////////////////////////////
int App_FindGenre(App *app, char *name, int cnt)
{
	int index = 0;
	Genre *genre = 0;

	for (index = 0; index<cnt; index++)
	{
		genre = (Genre *)MyArray_GetAt(app->genres, index);
		if (strcmp(name, genre->g_name) == 0)
			return index;
	}
	return -1;
}