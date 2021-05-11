#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "prototype.h"


int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0, log_pass_id = 0, result = 0, choice2_1 = 0,admin_id = 0;
	int var = 0,choice2_1_1 = 0,choice2_2_2 = 0;
	char ch;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
	dessifrovka();//Дешифрока данных для их последущего ипользования 
	while (1)
	{
		system("cls");
		choice1 = main_menu(choice1);
		if (choice1 == 1)
		{
			while (1)
			{   
				system("cls");
				choice2 = registration_menu(choice2);
				if (choice2 == 1)
				{
					registration();
					chesar();
				}
				if (choice2 == 2)
				{
					log_pass_id = check_user_pass(result);
					if (log_pass_id == 1)
					{
						while (1)
						{
							choice3 = user_menu(choice3);
							if (choice3 == 1)
							{
								output();
								break;
							}
							if (choice3 == 2)
							{

							}
							if (choice3 == 3)
							{

							}
							if (choice3 == 4)
							{
								break;
							}
						}
					}
				}
				if (choice2 == 3)
				{
					break;
				}
			}
		}
		if (choice1 == 2)
		{
			
			system("cls");
			admin_id = check_admin_pass(admin_id);
			if (admin_id == 1)
			{
				while (1)
				{
					system("cls");
					choice2_1 = admin_menu(choice2_1);
					if (choice2_1 == 1)
					{
						while (1)
						{
							system("cls");
							choice2_1_1 = work_with_account(choice2_1_1);
							if (choice2_1_1 == 1)
							{
								watch_user();
							}
							if (choice2_1_1 == 2)
							{
								add_user();
								chesar();
								watch_user();
							}
							if (choice2_1_1 == 3)
							{
								logpass_sort();
								chesar();
								watch_user();
								printf("Данные успешно отсортированы\n");
							}
							if (choice2_1_1 == 4)
							{
								user_mod();
								chesar();
							}
							if (choice2_1_1 == 5)
							{
								del_user();
								chesar();
							}
							if (choice2_1_1 == 6)
							{
								ban_user();
								chesar();
							}
							if (choice2_1_1 == 7)
							{
								
							}
							if (choice2_1_1 == 8)
							{
								break;
							}
						}
					}
					if (choice2_1 == 2)
					{
						while (1)
						{
							system("cls");
							choice2_2_2 = work_with_data(choice2_2_2);
							if (choice2_2_2 == 1)
							{
								watch_data();
							}
							if (choice2_2_2 == 2)
							{
								add_voucher_data();
							}
							if (choice2_2_2 == 3)
							{
								sort_voucher();
							}
							if (choice2_2_2 == 4)
							{
								//редактирование данных
							}
							if (choice2_2_2 == 5)
							{
								//удаление данных
							}
							if (choice2_2_2 == 6)
							{
								vacancy_search();
							}
							if (choice2_2_2 == 7)
							{
								break;
							}

						}
					}
					if (choice2_1 == 3)
					{
						break;
					}
				}
			}
			else {
				printf("Ошибка!!Ключ администратора введён не верно!\n");
				system("pause");
				break;
			}
		}
		if (choice1 == 3)
		{
			break;
		}
	}
    remove("D:/logpass.txt");//Удаление не зашифрованных данных*/
}


