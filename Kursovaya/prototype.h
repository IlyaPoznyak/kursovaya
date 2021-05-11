void registration();
void chesar();
void dessifrovka();
int check_user_pass(int result);
void output();
int main_menu(int choice1);
int registration_menu(int choice2);
int user_menu(int choice3);
int check_admin_pass(int admin_id);
int admin_menu(int choice2_1);
int work_with_account(int choice2_1_1);
int work_with_data(int cohoice2_2_2);
void watch_user();
void add_user();
int logpass_sort();
int del_user();
int user_mod();
int ban_user();
void add_voucher_data();
void sort_voucher();
void watch_data();
void vacancy_search();



static struct logpass {
	char login[30];
	char password[30];
}user;

static struct client { //информация о клиенте и о его путёвке
	int client_id;
	char fio[30];
	char addres[30];
	char number[10];
}info3;

static struct voucher { //Информация о путёвке
	int voucher_id;
	char duration_travel[10];
	char country[30];
	char climate[30];
	char hotel_name[30];
	struct client cli;
}info1;


static struct vacancy { //Информация о доступных путёвках
	char date_of_travel[25];
	int price;
	int discount;//скидка
}info2;
