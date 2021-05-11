#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "prototype.h"
#include <malloc.h>
using namespace std;


int log_pass_id = 0;
char admin_key[20];
void registration()
{
	char ch,password_id = 0,str[12];
	int len_login = 0,flag = 0;
	FILE* fp1;
	printf("Ваш логин и пароль должен состоять не более чем из 12 символов:\n\n");
	fp1 = fopen("d:/logpass.txt", "r");
	while (1)
	{
		printf("Введите свой логин:\n");
		while (((ch = getchar()) != EOF) && (ch != '\n'));//Очистка буфера
		gets_s(user.login);
		len_login = strlen(user.login);
		if (strlen(user.login) > 12)
		{
			printf("Ваш логин введён не верно:\n");
			system("pause");
			break;
		}
		while (!(feof(fp1)))
		{
			fgets(str, len_login + 1, fp1);
			if (strcmp(str, user.login) == 0)
			{
				system("cls");
				printf("Такой логин уже существует!!!\n");
				system("pause");
				flag = 1;
				break;//
			}
		}
		if (flag == 1)
		{
			break;
		}
		printf("Введите свой пароль:\n");
		gets_s(user.password);
		if (strlen(user.password) > 12)
		{
			printf("Ваш пароль введён не верно:\n");
			system("pause");
			break;
		}
		fclose(fp1);
		fp1 = fopen("d:/logpass.txt", "a");
		fprintf(fp1, "%s*", user.login);
		fprintf(fp1, "%s*|\n", user.password);
		fclose(fp1);
		printf("Вы успешно зарегестрировались!\n");
		system("pause");
		system("cls");
		break;
	}
	fclose(fp1);
}

void chesar()
{
	int n = 5,flag;
	char c;
	FILE* fp1,* fp2;
	fp1 = fopen("d:/logpass.txt", "r");
	fp2 = fopen("D:/Курсач/chesar.txt", "w");
	c = getc(fp1);
	while (!(feof(fp1)))
	{
		flag = 0;
		if (c >= 'a' && c <= 'z')
		{
			c = c + n;
			if (c > 'z') c = 'a' + (c - 'z') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= '0' && c <= '9')
		{
			c = c + n;
			if (c > '9') c = '0' + (c - '9') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'а' && c <= 'я')
		{
			c = c + n;
			if (c > 'я') c = 'а' + (c - 'я') - 1;
		}
		if (!flag) fprintf(fp2, "%c", c);
		c = getc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
}


void dessifrovka()
{
	int n = 5, flag;
	char c;
	FILE* fp1, * fp2;
	fp1 = fopen("d:/logpass.txt", "w");
	fp2 = fopen("D:/Курсач/chesar.txt", "r");
	c = getc(fp2);
	while (!(feof(fp2)))
	{
		flag = 0;
		if (c >= 'a' && c <= 'z')
		{
			c = c - n;
			if (c < 'a')
			{
				c = 'z' - ('a' - c) + 1;
			}
			fprintf(fp1, "%c", c);
			flag = 1;
		}
		if (c >= '0' && c <= '9')
		{
			c = c - n;
			if (c < '0')
			{
				c = '9' - ('0' - c) + 1;
			}
			fprintf(fp1, "%c", c);
			flag = 1;
		}
		if (c >= 'а' && c <= 'я')
		{
			c = c - n;
			if (c < 'а')
			{
				c = 'я' - ('а' - c) + 1;
			}
			fprintf(fp1, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf(fp1, "%c", c);
		c = getc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
}

int logpass_sort()
{
	int k = 0,i = 0,j;
	char temp[30];
	FILE* fp1;
	fp1 = fopen("d:/logpass.txt", "r");
	while (!feof(fp1))
	{
		fscanf_s(fp1, "%s", user.login, _countof(user.login));
		k++; // подсчёт количества строк в файле
	}
	if (k == 0)
	{
		printf("Файл пуст!!\n");
		return 0;
	}
	k = k - 1;
	char** arr = new char* [k]; // выделение памяти для двумерного массива
	for (int i = 0; i < 30; ++i)
	{
		arr[i] = new char[30];
	}
	i = 0;
	rewind(fp1);
	while (!feof(fp1))
	{
		fscanf_s(fp1, "%s", user.login, _countof(user.login));
		strcpy(arr[i], user.login); // считывем данные из файла в массив 
		i++;
	}
	fclose(fp1);
	for (i = 1; i < k; i++) //сортировка пузырьком
	{
		for (j = 0; j < k - i; j++) {
			if (strcmp(arr[j],arr[j + 1]) > 0)
			{
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
	fp1 = fopen("d:/logpass.txt", "w");
	for (i = 0; i < k; i++) {
		fprintf(fp1, "%s\n", arr[i]);
	}	
	fclose(fp1);
	delete[] arr;
	return 1;
}


int check_user_pass(int result)
{
	char ch,str1[80],str2[80];
	int i = 0,k = 0;
	FILE* fp1,*fp2;
	fp1 = fopen("d:/logpass.txt", "r");//База данных всех паролей
	fp2 = fopen("d:/chekpass.txt", "a");//Файл для записи текущего пароля введённого пользователем
	printf("Введите свой логин:\n");
	while (((ch = getchar()) != EOF) && (ch != '\n'));//Очистка буфера
	gets_s(user.login);
	fprintf(fp2, "%s*", user.login);
	printf("Введите свой пароль:\n");
	gets_s(user.password);
	fprintf(fp2, "%s*|\n", user.password);
	fclose(fp2);
	fp2 = fopen("d:/chekpass.txt", "r");
	fgets(str2, 80, fp2);
	while (!(feof(fp1)))
	{
		fgets(str1, 80, fp1);
		if (strcmp(str1, str2) == 0)
		{
			printf("Выход выполнен!!!\n");
			result = 1;
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("d:/chekpass.txt");//Сброс файла с поролями(если такой имеется)
	system("pause");
	system("cls");
	return result;
}

int check_admin_pass(int admin_id)
{
	char ch;
	printf("Введите ключ администратора:\n");
	while (((ch = getchar()) != EOF) && (ch != '\n'));//Очистка буфера
	gets_s(admin_key);
	if (strcmp(admin_key,"admin") == 0)
	{
		printf("Вход в режим админа выполнен успешно!\n");
		system("pause");
		system("cls");
		return 1;
	}
	else {
		return 0;
	}
}
int main_menu(int choice1)
{
	printf("---------Меню---------\n");
	printf("1.Вход под пользователем\n");
	printf("2.Вход под администратором\n");
	printf("3.Выход из программы\n");
	scanf_s("%d", &choice1);
	system("cls");
	return choice1;
}

int registration_menu(int choice2)
{
	printf("1.Регистрация аккаунта:\n");
	printf("2.Вход в систему\n");
	printf("3.Выход в главное меню\n");
	scanf_s("%d", &choice2);
	system("cls");
	return choice2;
}

int user_menu(int choice3)
{
	printf("1.Просмотреть данные:\n");
	printf("2.Поиск:\n");
	printf("3.Сортировка данных:\n");
	printf("4.Выход в меню авторизации:\n");
	scanf_s("%d", &choice3);
	return choice3;
}

int admin_menu(int choice2_1)
{
	printf("1.Работа с учётными записями:\n");
	printf("2.Работа с данными:\n");
	printf("3.Выход в главное меню:\n");
	scanf_s("%d", &choice2_1);
	return choice2_1;
}

int work_with_account(int choice2_1_1)
{
	printf("1.Просмотр учётных записей\n");
	printf("2.Добавление учётной записи пользователя\n");
	printf("3.Сортировка учётных записей(в алфавитном порядке)\n");
	printf("4.Редактирование учётной записи\n");
	printf("5.Удаление учётной записи\n");
	printf("6.Блокирование учётной записи\n");//пользователь увидит сообщение о бане
	printf("7.Разблокировка учётной записи\n");
	printf("8.Выход в главное меню администратора\n");
	scanf_s("%d", &choice2_1_1);
	return choice2_1_1;
}

int work_with_data(int choice2_2_2) {
	printf("1.Просмотр данных\n");
	printf("2.Добавление данных\n");
	printf("3.Сортировка данных\n");
	printf("4.Редактирование данных\n");
	printf("5.Удаление данных\n");
	printf("6.Поиск данных\n");
	printf("7.Выход в главное меню администратора\n");
	scanf_s("%d", &choice2_2_2);
	return choice2_2_2;
}



