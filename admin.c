//admin: administrator
//2022.03.21 done all basic functions.

#include "basic.h"

//函数声明
extern void adminMenu();
extern void admin_showUsers(int count);
extern void admin_mngd(int goods_count);
extern int admin_chgdinfo(int project, int i);
extern void admin_showOrders(int count);
extern void admin_userLogout(int count);

const char Admin_Password[30] = { "WhaleMarketAdmin8727" };
const char test_Admin_Password[30] = { "123" };

extern void adminLogin() {
	cls_ad();
	printf("Administrator login\n");
	printf("Please enter administrator password: ");
	char scanfPassword[30] = { "" };
	scanf_s("%s", &scanfPassword, 30);
	int is_password = strcmp(scanfPassword, test_Admin_Password);
	//strcmp: 比较两个字符串，相同则返回0
	if (is_password == 0) {
		printf("Admin login successfully\n");
		adminMenu();
	}
	else {
		printf("Wrong password.Please try again.");
		Sleep(750);
		cls_ad();
		adminLogin();
	}
}

extern void adminMenu() {
	int choose = 0;
	while (choose != 5) {
		cls_ad();
		shm(3);
		printf("\nPlease enter operation number: ");
		scanf_s("%d", &choose);
		switch (choose) 
		{
		case 1:
			admin_mngd(goods_count);
			break;
		case 2:
			admin_showOrders(order_count);
			break;
		case 3:
			admin_showUsers(user_count);
			break;
		case 4:
			admin_userLogout(user_count);
			break;
		case 5:
			cls_ad();
			break;
		default:
			printf("Wrong operation number.Please try again.\n");
			Sleep(1250);
			cls_ad();
			break;
		}
	}
}

extern void admin_showUsers(int count) {
	int i;
	cls_ad();
	printf("|User ID  |bos\t|name\t|tel\t\t|address\t\t|balance\n");
	for (i = 0; i < count; i++)
	{
		printf("|%d    ", user[i].UID);
		printf("|%d\t", user[i].bos);
		printf("|%.20s\t", user[i].name);
		printf("|%.15s\t", user[i].tel);
		printf("|%.50s\t", user[i].address);
		printf("|%.2f\n", user[i].balance);
	}
	printf("\nPlease enter 0 to continue: ");
	char is_cls[10] = { "" };
	scanf_s("%s", &is_cls, 10);
}

extern void admin_showGoods(int count) {
	int i;
	cls_ad();
	printf("|Goods ID |name\t\t\t|price\t|description\t\t\t\t\t|condition\n");
	for (i = 0; i < count; i++)
	{
		printf("|%d    ", goods[i].GID);
		printf("|%.20s\t", goods[i].name);
		printf("|%.2f\t", goods[i].price);
		printf("|%.60s\t", goods[i].des);
		printf("|%d\n", goods[i].condition);
	}
}

extern void admin_mngd(int goods_count) {
	//mngd: Manage Goods
	//steps: 1.show all goods; 2.choose goods to manage; 3.show menu4
	int enterGID = -1;
	while (enterGID != 0) {
		cls_ad();
		admin_showGoods(goods_count);
		printf("\nPlease choose goods to manage(enter GID)(enter 0 to come back) :");
		scanf_s("%d", &enterGID);
		if (enterGID == 0) { break; }
		int i, flag = 0, project = 0, is_exit = 0;
		//search goods
		for (i = 0; i < goods_count; i++) {
			if (enterGID == goods[i].GID) {
				while (is_exit != 5) {
					//show goods information
					cls_ad();
					printf("\nThe information of the goods:\n\n");
					printf("|Goods ID |name\t\t\t|price\t|description\t\t\t\t\t|condition\n");
					printf("|%d    ", goods[i].GID);
					printf("|%.20s\t", goods[i].name);
					printf("|%.2f\t", goods[i].price);
					printf("|%.60s\t", goods[i].des);
					printf("|%d\n\n", goods[i].condition);
					flag = 1;
					is_exit = admin_chgdinfo(project, i);
					//function "admin(chgdinfo)" returns "project", project 5 refers to coming back(exit)
					if (is_exit == 5) { break; }
				}
			}
		}
		if (flag == 0) {
			printf("\nUndefined GID.Please try again.\n");
			Sleep(1500);
			cls_ad();
		}
	}
}

extern int admin_chgdinfo(int project, int i) {
	//chgd: change goods information
	shm(4);
	printf("Please enter the project to change(enter operation number) :");
	scanf_s("%d", &project);
	switch (project)
	{
	case 1:
		printf("Please enter new goods name:");
		scanf_s("%s", &goods[i].name, 20);
		printf("Changed successfully!\n");
		Sleep(750);
		cls_ad();
		break;
	case 2:
		printf("Please enter new goods price:");
		scanf_s("%f", &goods[i].price);
		printf("Changed successfully!\n");
		Sleep(750);
		cls_ad();
		break;
	case 3:
		printf("Please enter new goods description:");
		scanf_s("%s", &goods[i].des, 60);
		printf("Changed successfully!\n");
		Sleep(750);
		cls_ad();
		break;
	case 4:
		printf("Please enter new goods condition(0~2) :");
		scanf_s("%d", &goods[i].condition);
		printf("Changed successfully!\n");
		Sleep(750);
		cls_ad();
		break;
	case 5:
		cls_ad();
		break;
	default:
		printf("Wrong operation number.Please try again.\n");
		Sleep(1750);
		cls_ad();
		break;
	}
	return project;
}

extern void admin_showOrders(int count) {
	int i;
	cls_ad();
	printf("|Order ID |Buyer ID |Seller ID|Goods ID |name\t\t\t|number |price\t|address\t\t|time\n");
	for (i = 0; i < count; i++)
	{
		printf("|%d    ", order[i].OID);
		printf("|%d    ", order[i].bid);
		printf("|%d    ", order[i].sid);
		printf("|%d    ", order[i].gid);
		printf("|%.20s\t\t", order[i].gn);
		printf("|%d\t", order[i].number);
		printf("|%.2f\t", order[i].price);
		printf("|%.50s\t", order[i].address);
		printf("|%.30s\n", order[i].time);
	}
	printf("\nPlease enter 0 to continue: ");
	char is_cls[10] = { "" };
	scanf_s("%s", &is_cls, 10);
}

extern void admin_userLogout(int count) {
	int i;
	int enterUID = -1;
	while (enterUID != 0) {
		cls_ad();
		printf("Please enter the user\'s UID(enter 0 to come back) : ");
		scanf_s("%d", &enterUID);
		if (enterUID == 0) { break; }
		if (enterUID != 0) {
			int flag = 0;
			for (i = 0; i < count; i++) {
				if (enterUID == user[i].UID) {
					flag = 1;
					printf("The information of this user:\n");
					printf("|User ID  |bos\t|name\t|tel\t\t|address\t\t|balance\n");
					printf("|%d    ", user[i].UID);
					printf("|%d\t", user[i].bos);
					printf("|%.20s\t", user[i].name);
					printf("|%.15s\t", user[i].tel);
					printf("|%.50s\t", user[i].address);
					printf("|%.2f\n", user[i].balance);
					printf("\nAre you sure to logout this account?(0:yes / 1:no) :");
					int is_logout = -1, flag_logout = -1;
					scanf_s("%d", &is_logout);
					if (is_logout == 0) {
						for (int j = i; j < count; j++) {
							user[j] = user[j + 1];
						}
						user_count--;
						printf("\nLogouted successfully.\n");
						Sleep(1000);
						flag_logout = 0;
						adminMenu();
					}
					if (is_logout == 1) {
						break;
					}
					if (flag_logout == -1) {
						printf("\nFailed.Please try again.\n");
						Sleep(1000);
						cls_ad();
					}
				}
			}	
			if (flag == 0) {
				printf("\nUndefined UID.Please try again.\n");
				Sleep(1500);
				cls_ad();
			}
		}
	}
}