#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdilb.h>
#include<conio.h>
#include<string.h>
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void color(int c)
{
	SetConsoleTestAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
float aic(float x,float n)
{
	float r;
	float m;
	m=n-x;
	srand((unsigned)time(NULL));
	r=(rand()%m)+n;
	return r;
}
