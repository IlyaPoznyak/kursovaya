#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "prototype.h"
#include <math.h>



void watch_user()
{
	system("cls");
	char ch;
	FILE* fp1;
	fp1 = fopen("d:/logpass.txt", "r");
	do
	{
		ch = fgetc(fp1);
		putchar(ch);
	} while (ch != EOF);
	system("\npause");
	system("cls");
	fclose(fp1);
}

void add_user()
{
	char ch, password_id = 0;
	FILE* fp1;
	system("cls");
	printf("����� � ������ ������ �������� �� ����� ��� �� 12 ��������:\n\n");
	fp1 = fopen("d:/logpass.txt", "a");
	while (1)
	{
		printf("���� ������ ��� ����������\n");
		while (((ch = getchar()) != EOF) && (ch != '\n'));//������� ������
		gets_s(user.login);
		if (strlen(user.login) > 12)
		{
			printf("������ ���������� ������!!\n");
			system("pause");
			break;
		}
		printf("���� ������ ��� ����������\n");
		gets_s(user.password);
		if (strlen(user.password) > 12)
		{
			printf("������ ���������� ������!!\n");
			system("pause");
			break;
		}
		fprintf(fp1, "%s*", user.login);
		fprintf(fp1, "%s*|\n", user.password);
		printf("����� ������������ ������� �������� � ���� ������\n");
		system("pause");
		system("cls");
		break;
	}
	fclose(fp1);
}

int del_user()
{
	system("cls");
	logpass *mas;
	FILE* fp1;
	int k = 0, n;
	fp1 = fopen("d:/logpass.txt", "r");
	while (!feof(fp1))
	{
		fscanf_s(fp1, "%s", user.login, _countof(user.login));
		k++;
		printf("������������ �%d:%s\n",k,user.login);
	}
	if (k == 1)
	{
		printf("���� ����!!\n");
		system("pause");
		return 0;
	}
	rewind(fp1);
	k = k - 1;
	mas = new logpass[k];
	for (int i = 0; i < k; i++)
	{
		fscanf_s(fp1, "%s", mas[i].login, _countof(mas[i].login)); //����������� ������ � ������
	}
	rewind(fp1);
	fclose(fp1);
	while (1)
	{
		printf("������� ����� ������ ��� ��������\n");
		scanf_s("%d", &n);
		if (n > 0 && n <= k) break;
		else printf("������!\n");
	}
	fp1 = fopen("d:/logpass.txt", "w");
	for (int i = 0; i < k; i++)
	{
		if (i + 1 == n)
		{
			continue;
		}
		fprintf(fp1, "%s\n", mas[i].login);
	}
	rewind(fp1);
	delete[] mas;
	fclose(fp1);
	return 1;
}

int user_mod()
{
	logpass * mas;
	FILE* fp1;
	int k = 0, n, m;
	fp1 = fopen("d:/logpass.txt", "r");
	while (!feof(fp1))
	{
		fscanf_s(fp1, "%s", user.login, _countof(user.login));// ������� ���-�� �����
		k++;
		printf("������������ �%d:%s\n", k, user.login);
	}
	if (k == 1)
	{
		printf("���� ����!!\n");
		system("pause");
		return 0;
	}
	rewind(fp1);
	k = k - 1;
	mas = new logpass[k];
	for (int i = 0; i < k; i++)
	{
		fscanf_s(fp1, "%s", mas[i].login, _countof(mas[i].login));//���������� ������ � ������
	}
	rewind(fp1);
	fclose(fp1);
	while (1)
	{
		printf("������� ����� ������ ��� �����������\n");
		scanf_s("%d", &n);
		if (n > 0 && n <= k) break;
		else printf("������!\n");
	}
	printf("������� ����� ����� � ������\n"); 
	printf("������ �����:(�����*������*|)\n");
	gets_s(mas[n - 1].login);
	fp1 = fopen("d:/logpass.txt", "w");
	for (int i = 0; i < k; i++)
	{
		fprintf(fp1, "%s\n", mas[i].login);
	}
	rewind(fp1);
	fclose(fp1);
	system("pause");
	delete[] mas;
	return 1;
}

int ban_user()
{
	int k = 0,n = 0;
	FILE* fp1;
	logpass* mas;
	fp1 = fopen("d:/logpass.txt", "r");
	while (!feof(fp1))
	{
		fscanf_s(fp1, "%s", user.login, _countof(user.login));
		k++;
		//printf("������������ �%d:%s %s\n", k, user.login,user.ban_id);
	}
	if (k == 1)
	{
		printf("���� ����!!\n");
		system("pause");
		return 0;
	}
	rewind(fp1);
	k = k - 1;
	mas = new logpass[k];
	for (int i = 0; i < k; i++)
	{
		fscanf_s(fp1, "%s", mas[i].login, _countof(mas[i].login));//���������� ������ � ������
	}
	rewind(fp1);
	fclose(fp1);
	while (1)
	{
		printf("������� ����� ������������ ��� ����\n");
		scanf_s("%d", &n);
		if (n > 0 && n <= k) break;
		else printf("������!\n");
	}
	fp1 = fopen("d:/logpass.txt", "w");
	for (int i = 0; i < k; i++)
	{
		if (i + 1 == n)
		{
			fprintf(fp1, "%s $\n", mas[i].login);
			continue;
		}
		fprintf(fp1, "%s\n", mas[i].login);
	}
	rewind(fp1);
	delete[] mas;
	fclose(fp1);
	system("pause");
	return 1;
}


void add_voucher_data()
{
	int choice1 = 0,choice2 = 0,i = 0,tmp;
	char ch;
	FILE* fp1,*fp2,*fp3;
	system("cls");
	fp1 = fopen("D:/������/voucher.txt", "a");
	printf("������� id ������\n");
	scanf_s("%d", &info1.voucher_id);
	printf("������� ����������������� �����������(� ����)\n");
	while (((ch = getchar()) != EOF) && (ch != '\n'));//������� ������
	gets_s(info1.duration_travel);
	printf("������� ������\n");
	gets_s(info1.country);
	printf("������� ������(����������� � ��������)\n");
	gets_s(info1.climate);
	printf("������� �������� �����\n");
	gets_s(info1.hotel_name);
	fprintf(fp1, "%d ", info1.voucher_id);
	fprintf(fp1, "*%s ", info1.duration_travel);
	fprintf(fp1, "*%s ", info1.country);
	fprintf(fp1, "*%s ", info1.climate);
	fprintf(fp1, "*%s|\n", info1.hotel_name);
	/*fprintf(fp1, "%d", &info1.cli.client_id);
	fprintf(fp1, "*%s", info1.cli.fio);*/
	fclose(fp1);
	system("cls");
	printf("������ ������� ��������\n");
	system("pause");
}

void sort_voucher() //���������� �� �������� ���������
{
	int kolvo = 0,i = 0,tmp = 0,k = 0;
	char ch;
	voucher* mas;
	FILE* fp1 = fopen("D:/������/voucher.txt", "r");
	ch = fgetc(fp1);
	while(ch != EOF)
	{
		ch = fgetc(fp1);
		if (ch == '|')
		{
			k++; // ������� ���-�� ����� � �����
		}
	}
	rewind(fp1);
	mas = new voucher[k];
	while (i < k)
	{
		fscanf_s(fp1, "%d", &mas[i].voucher_id);
		fscanf_s(fp1, "%s", mas[i].duration_travel, _countof(mas[i].duration_travel));
		fscanf_s(fp1, "%s", mas[i].country, _countof(mas[i].country));
		fscanf_s(fp1, "%s", mas[i].climate, _countof(mas[i].climate));
		fscanf_s(fp1, "%s", mas[i].hotel_name, _countof(mas[i].hotel_name));
		/*printf("%d\n", mas[i].voucher_id);
		printf("%s\n", mas[i].duration_travel);
		printf("%s\n", mas[i].country);
		printf("%s\n", mas[i].climate);
		printf("%s\n", mas[i].hotel_name);*/
		i++;
	}
	for (i = 0; i < k; i++)
	{
		for (int j = 0; j < k - i; j++)
		{
			if (mas[j].voucher_id > mas[j + 1].voucher_id)
			{
				tmp = mas[j].voucher_id;
				mas[j].voucher_id = mas[j + 1].voucher_id;
				mas[j + 1].voucher_id = tmp;
			}
		}
	}
	fclose(fp1);
	fp1 = fopen("D:/������/voucher.txt", "w");
	for (i = 0; i < k; i++)
	{
		fprintf(fp1, "%d ", mas[i].voucher_id);
		fprintf(fp1, "%s ", mas[i].duration_travel);
		fprintf(fp1, "%s ", mas[i].country);
		fprintf(fp1, "%s ", mas[i].climate);
		fprintf(fp1, "%s\n", mas[i].hotel_name);
	}
	fclose(fp1);
	delete[] mas;
	system("pause");
}

void watch_data() {
	char ch;
	FILE* fp1 = fopen("D:/������/voucher.txt", "r");
	while (!(feof(fp1)))
	{
		ch = fgetc(fp1);
		putchar(ch);
	}
	fclose(fp1);
	system("pause");
}


void vacancy_search()
{
	int k = 0,i = 0,item = 0;
	char ch;
	voucher* mas;
	FILE* fp1 = fopen("D:/������/voucher.txt", "r");
	ch = fgetc(fp1);
	while(ch != EOF)
	{
		ch = fgetc(fp1);
		if (ch == '|')
		{
			k++; // ������� ���-�� ����� � �����
		}
	}
	mas = new voucher[k];
	while (i < k)
	{
		fscanf_s(fp1, "%d", &mas[i].voucher_id);
		fscanf_s(fp1, "%s", mas[i].duration_travel, _countof(mas[i].duration_travel));
		fscanf_s(fp1, "%s", mas[i].country, _countof(mas[i].country));
		fscanf_s(fp1, "%s", mas[i].climate, _countof(mas[i].climate));
		fscanf_s(fp1, "%s", mas[i].hotel_name, _countof(mas[i].hotel_name));
		i++;
	}
	fclose(fp1);
	printf("������� id ������ ��� ������\n");
	scanf_s("%d", &item);
	for (i = 0; i < k; i++)
	{
		if (mas[i].voucher_id == item)
		{
			printf("������ ������� �������!!\n");
			printf("|id ������:%d|������������ ����������� %s ����|������ %s|������ %s|�������� ����� %s|\n",
				mas[i].voucher_id, mas[i].duration_travel, mas[i].country, mas[i].climate, mas[i].hotel_name);
			system("pause");
			break;
		}
	}
	printf("������ �� �������!!\n");
	system("pause");
}
