#pragma once
enum ehkey
{
	NOT_DEFINED,
	ESC, F1,F2,F3,F4,F5,F6,F7,F8,
};
int getnum();
void getstr(char *buffer,int n);
 int getkey();