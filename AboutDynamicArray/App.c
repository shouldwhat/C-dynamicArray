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
			default: printf("다시 입력하세요.\n");
		}

		getkey();
	}
}
int SelectMenu()
{
	system("cls");
	printf("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐\n");
	printf("ㅣ   장르별 도서 관리 프로그램 - Show ㅣ\n");
	printf("ㅣ                         2014. 5.12 ㅣ\n");
	printf("ㅣ                         by. 김원규 ㅣ\n");
	printf("└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘\n");
	printf(" F1: 장르 추가\n");
	printf(" F2: 장르 삭제\n");
	printf(" F3: 장르 목록 보기\n");
	printf(" F4: 도서 추가\n");
	printf(" F5: 도서 제거\n");
	printf(" F6: 모든 책 목록\n");
	printf(" F7: 선택 장르 도서 목록\n");
	printf(" F8: ISBN으로 도서 검색\n");

	return getkey();
}

void App_AddGenre(App *app)
{
	char name[MAX + 1];
	Genre *genre;
	int flag;

	printf("\n추가할 장르 이름을 입력하세요.\n");
	getstr(name, MAX);

	flag = App_FindGenre(app, name, app->g_num);

	if (flag != -1)
	{
		printf("같은 장르가 존재 합니다\n");
		return;
	}
	else
	{
		genre = Genre_newGenre(name, (app->g_num) + 1);
		MyArray_Add(app->genres, genre);
		app->g_num++;
	}

	printf("아무 키나 누르세요.\n");
}
void App_DelGenre(App *app)
{
	char g_name[MAX + 1];
	int index;
	Genre *genre;

	printf("삭제할 장르명을 입력하세요.\n");
	getstr(g_name, MAX);

	index = App_FindGenre(app, g_name, app->g_num);
	if (index == -1)
	{
		printf("해당 장르가 존재하지 않습니다.\n");
		return;
	}
	genre = (Genre *)MyArray_GetAt(app->genres, index);
	free(genre);

	printf("아무 키나 누르세요.\n");
}
void App_ListGenre(App *app)
{
	int g_cnt, n = 0;
	Genre *genre;

	printf("\n");
	g_cnt = app->g_num;
	if (app->g_num == 0)
		printf("\n존재하는 장르가 없습니다\n");
	else
	{
		for (n = 0; n<g_cnt; n++)
		{
			genre = (Genre *)MyArray_GetAt(app->genres, n);
			printf("%d번: %s\n", n + 1, Genre_GetName(genre));
		}
	}
	printf("아무 키나 누르세요.\n");
}
void App_AddBook(App *app)
{
	char g_name[MAX + 1];
	char b_name[MAX + 1];
	int b_isbn;
	int index;

	printf("추가를 원하는 장르를 입력하세요.\n");
	getstr(g_name, MAX);

	index = App_FindGenre(app, g_name, app->g_num);
	if (index == -1)
	{
		printf("\n해당 장르가 존재하지 않습니다.\n");
		return;
	}
	else
	{
		printf("책 제목을 입력하세요.\n");
		getstr(b_name, MAX);
		printf("책의 ISBN을 입력하세요.\n");
		b_isbn = getnum();

		Genre_AddBook((Genre *)MyArray_GetAt(app->genres, index), b_name, b_isbn);
	}
	printf("아무 키나 누르세요.\n");
}
void App_DelBook(App *app)
{
	printf("도서 제거 함수 실행\n");
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

	printf("아무 키나 누르세요.\n");
}
void App_ViewBooksAtGenre(App *app)
{
	char g_name[MAX + 1];
	int index;
	int n = 0;
	Genre *genre;

	printf("원하는 장르를 입력하세요.\n");
	getstr(g_name, MAX);
	index = App_FindGenre(app, g_name, app->g_num);

	if (index == -1)
	{
		printf("\n해당 장르가 존재하지 않습니다.\n");
		return;
	}
	else
	{
		genre = (Genre *)MyArray_GetAt(app->genres, index);
		Genre_ViewBookAll(genre, genre->books->cnt);
	}
	printf("아무 키나 누르세요.\n");
}
void App_FindBookByIsbn(App *app)
{
	int isbn, flag;
	char g_name[MAX + 1];
	int index;
	Genre *genre;

	printf("장르명을 입력하세요.\n");
	getstr(g_name, MAX);

	index = App_FindGenre(app, g_name, app->g_num);

	if (index == -1)
	{
		printf("\n해당 장르가 존재하지 않습니다.\n");
		return;
	}
	else
	{
		genre = (Genre *)MyArray_GetAt(app->genres, index);
		printf("찾으려는 ISBN을 입력하세요.\n");
		isbn = getnum();
		flag = Genre_FindBook(genre, isbn, genre->books->cnt);

		if (flag == -1)
			printf("\n해당 책이 존재하지 않습니다.\n");

	}
	printf("아무 키나 누르세요.\n");
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