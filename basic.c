#include "basic.h"

//test data
struct users_info user[] = { { 10001, 0, "123456", "Jane", "168-8686-6868", "Canada/1321/46541", 9999.99 }, { 10002, 1, "654321", "Pigsy", "188-8888-8888", "Here_here_here_here", 100.86 }, {10003, 0, "asdfgh", "alien", "123-4567-8910", "There_there_there_1", 0.00} };
struct goods_info goods[] = { { 20001, 0, 19.90, "�޹�����AD����", "����������������������������������������������"}, { 20002, 2, 5.00, "��̳���ţ����", "������̳�žŰ�ʮһ�췢�ͣ�����ˬ�������ڣ�"}, { 20003, 1, 9.9, "iPhone 13 Pro", "��ƴ��༴��ƻ���ֻ����ٷ���Ʒ����һ��ʮ"}};
struct orders_info order[] = { { 30001, 10001, 10002, 20001, "�޹�����AD����", 2, 39.80, "Canada/1321/46541", "2022.02.31"}, { 30002, 10003, 10002, 20003, "iPhone 13 Pro", 100, 990, "There_there_there_1", "2022.13.32" }, { 30003, 10003, 10002, 20002, "��̳���ţ����", 1, 5.00, "There_there_there_1", "2022.13.32"}};
user_count = 3;
goods_count = 3;
order_count = 3;

void welcome() {
	Sleep(500);

	system("color 01");
	printf("\n\n\n");
	printf("%s", banner);
	Sleep(750);
	system("color 09");
	Sleep(1750);
	system("color 01");
	Sleep(750);

	system("cls");
	system("color 07");
	printf("\n\tloading.");
	Sleep(666);
	printf(".");
	Sleep(666);
	printf(".");
	Sleep(666);
	system("cls");
}

void cls() {
	//cls: Clear Screen
	system("cls");
	printf("%s", menu[0]);
}

void cls_ad() {
	//cls_ad: Clear Screen for Administrator
	system("cls");
	printf("\n\t\t Welcome to Whale Market  |  Administrator \n\n");
}

void shm(int i) {
	//shm: Show Menu
	printf("%s", menu[i]);
}

void loading() {
	cls();
	double i = 0.000000;
	while (1) {
		printf("\t���ڼ���...\n\n\t%.6f�������", i);
		Sleep(1234);
		cls();
		i += 0.000001;
	}
}