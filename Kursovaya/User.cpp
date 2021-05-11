#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "prototype.h"
#include <malloc.h>
using namespace std;

void output()
{
	system("cls");
	char ch;
	FILE* fp1;
	fp1 = fopen("D:/Курсач/data.txt", "r");
	do
	{
		ch = fgetc(fp1);
		putchar(ch);
	} while (ch != EOF);
	system("pause");
	system("cls");
}

int data_sort() 
{

}
