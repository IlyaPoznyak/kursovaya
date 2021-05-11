#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main()
{
	int k = 0;
	char line[30];
	FILE* fp1;
	fp1 = fopen("d:/logpass.txt", "r");
	while (!(feof(fp1)))//считаем колво строк в файле
	{
		fscanf_s(fp1, "%s", line,_countof(line));
		k++;
	}
	fclose(fp1);
	*mas = new 
	fp1 = fopen("d:/logpass.txt", "r");
	while (!(feof(fp1)))
	{

	}
}