#include "ehcommon.h"
#include <stdio.h>
#include <conio.h>
 int getnum()
 {
	 int num = 0;
	 scanf("%d",&num);
	 fflush(stdin);
	 return num;
 }
 void getstr(char *buffer,int n)
 {
	 int i = 0;
	 for(i=0;i<n;i++)
	 {
		 buffer[i] = getchar();
		 if(buffer[i]=='\n')
		 {
			 break;
		 }
	 }
	 buffer[i]='\0';
	 fflush(stdin);
 }
int getkey()
{
	int key = 0;
	key = _getch();
	if(key == 27)
	{
		return ESC;
	}
	if(key == 0)
	{
		key = _getch();
		switch(key)
		{
		case 59: return F1;
		case 60: return F2;
		case 61: return F3;
		case 62: return F4;
		case 63: return F5;
		case 64: return F6;
		case 65: return F7;
		case 66: return F8;
		}
	}
	return NOT_DEFINED;
}